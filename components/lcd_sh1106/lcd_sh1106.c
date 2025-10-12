/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdlib.h>
#include <sys/cdefs.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_lcd_panel_interface.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_commands.h"
#include "lcd_sh1106.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_check.h"

static const char *TAG = "sh1106";

#define LCD_SH1106_I2C_CMD  0X00
#define LCD_SH1106_I2C_RAM  0X40

#define LCD_SH1106_PARAM_ONOFF          0xAE
#define LCD_SH1106_PARAM_MIRROR_X       0xA0
#define LCD_SH1106_PARAM_MIRROR_Y       0xC0
#define LCD_SH1106_PARAM_INVERT_COLOR   0xA6

static esp_err_t panel_sh1106_del(esp_lcd_panel_t *panel);
static esp_err_t panel_sh1106_reset(esp_lcd_panel_t *panel);
static esp_err_t panel_sh1106_init(esp_lcd_panel_t *panel);
static esp_err_t panel_sh1106_draw_bitmap(esp_lcd_panel_t *panel, int x_start, int y_start, int x_end, int y_end, const void *color_data);
static esp_err_t panel_sh1106_invert_color(esp_lcd_panel_t *panel, bool invert_color_data);
static esp_err_t panel_sh1106_mirror(esp_lcd_panel_t *panel, bool mirror_x, bool mirror_y);
static esp_err_t panel_sh1106_swap_xy(esp_lcd_panel_t *panel, bool swap_axes);
static esp_err_t panel_sh1106_set_gap(esp_lcd_panel_t *panel, int x_gap, int y_gap);
static esp_err_t panel_sh1106_disp_on_off(esp_lcd_panel_t *panel, bool off);

typedef struct {
    esp_lcd_panel_t base;
    esp_lcd_panel_io_handle_t io;
    int reset_gpio_num;
    bool reset_level;
    int x_gap;
    int y_gap;
    unsigned int bits_per_pixel;
    bool swap_axes;
} sh1106_panel_t;

esp_err_t esp_lcd_new_panel_sh1106(const esp_lcd_panel_io_handle_t io, const esp_lcd_panel_dev_config_t *panel_dev_config, esp_lcd_panel_handle_t *ret_panel)
{
    esp_err_t ret = ESP_OK;
    sh1106_panel_t *sh1106 = NULL;
    ESP_GOTO_ON_FALSE(io && panel_dev_config && ret_panel, ESP_ERR_INVALID_ARG, err, TAG, "invalid argument");
    ESP_GOTO_ON_FALSE(panel_dev_config->bits_per_pixel == 1, ESP_ERR_INVALID_ARG, err, TAG, "bpp must be 1");
    sh1106 = calloc(1, sizeof(sh1106_panel_t));
    ESP_GOTO_ON_FALSE(sh1106, ESP_ERR_NO_MEM, err, TAG, "no mem for sh1106 panel");

    if (GPIO_IS_VALID_OUTPUT_GPIO(panel_dev_config->reset_gpio_num)) {
        gpio_config_t io_conf = {
            .mode = GPIO_MODE_OUTPUT,
            .pin_bit_mask = 1ULL << panel_dev_config->reset_gpio_num,
        };
        ESP_GOTO_ON_ERROR(gpio_config(&io_conf), err, TAG, "configure GPIO for RST line failed");
    }

    sh1106->io = io;
    sh1106->bits_per_pixel = panel_dev_config->bits_per_pixel;
    sh1106->reset_gpio_num = panel_dev_config->reset_gpio_num;
    sh1106->reset_level = panel_dev_config->flags.reset_active_high;
    sh1106->base.del = panel_sh1106_del;
    sh1106->base.reset = panel_sh1106_reset;
    sh1106->base.init = panel_sh1106_init;
    sh1106->base.draw_bitmap = panel_sh1106_draw_bitmap;
    sh1106->base.invert_color = panel_sh1106_invert_color;
    sh1106->base.set_gap = panel_sh1106_set_gap;
    sh1106->base.mirror = panel_sh1106_mirror;
    sh1106->base.swap_xy = panel_sh1106_swap_xy;
#if ESP_IDF_VERSION < ESP_IDF_VERSION_VAL(5, 0, 0)
    sh1106->base.disp_off = panel_sh1106_disp_on_off;
#else
    sh1106->base.disp_on_off = panel_sh1106_disp_on_off;
#endif
    *ret_panel = &(sh1106->base);
    ESP_LOGD(TAG, "new sh1106 panel @%p", sh1106);

    return ESP_OK;

err:
    if (sh1106) {
        if (GPIO_IS_VALID_OUTPUT_GPIO(panel_dev_config->reset_gpio_num)) {
            gpio_reset_pin(panel_dev_config->reset_gpio_num);
        }
        free(sh1106);
    }
    return ret;
}

static esp_err_t panel_sh1106_del(esp_lcd_panel_t *panel)
{
    sh1106_panel_t *sh1106 = __containerof(panel, sh1106_panel_t, base);
    if (GPIO_IS_VALID_OUTPUT_GPIO(sh1106->reset_gpio_num)) {
        gpio_reset_pin(sh1106->reset_gpio_num);
    }
    ESP_LOGD(TAG, "del sh1106 panel @%p", sh1106);
    free(sh1106);
    return ESP_OK;
}

static esp_err_t panel_sh1106_reset(esp_lcd_panel_t *panel)
{
    sh1106_panel_t *sh1106 = __containerof(panel, sh1106_panel_t, base);

    // perform hardware reset
    if (GPIO_IS_VALID_OUTPUT_GPIO(sh1106->reset_gpio_num)) {
        gpio_set_level(sh1106->reset_gpio_num, sh1106->reset_level);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(sh1106->reset_gpio_num, !sh1106->reset_level);
        vTaskDelay(pdMS_TO_TICKS(10));
    }

    return ESP_OK;
}

// РЕКОМЕНДОВАНА ПОСЛІДОВНІСТЬ (SSD1306-style init + page addressing)
static const uint8_t vendor_specific_init[] = {
    0xAE,             // display OFF
    0xD5, 0x80,       // clock divide + oscillator
    0xA8, 0x3F,       // multiplex 1/64
    0xD3, 0x00,       // display offset 0
    0x40,             // start line 0
    0x8D, 0x14,       // charge pump ON (SSD1306)
    0x20, 0x02,       // Memory Addressing Mode = Page
    0xA1,             // segment remap
    0xC8,             // COM scan dir
    0xDA, 0x12,       // COM pins
    0x81, 0xCF,       // contrast (можеш лишити 0x7F, якщо занадто яскраво)
    0xD9, 0xF1,       // precharge (або 0x22 — м’якше)
    0xDB, 0x40,       // VCOMH
    0x2E,             // deactivate scroll
    0xA4,             // resume RAM
    0xA6,             // normal display
    // 0xAF,          // Display ON (можеш тримати вимкнено: у тебе є esp_lcd_panel_disp_on_off(true))
    0xFF              // END
};

/*
static const uint8_t vendor_specific_init[] = {
    // SH1106 recommended power-on init (per datasheet)
    0xAE,                   // Display OFF
    0xD5, 0x80,             // Display clock divide ratio/oscillator frequency (POR)
    0xA8, 0x3F,             // Multiplex ratio: 1/64
    0xD3, 0x00,             // Display offset: 0
    0x40,                   // Start line: 0
    0x8D, 0x14,             // Charge pump setting (from SSD1306)
    0xDA, 0x12,             // Common pads hardware config: alternative (POR)
    0x81, 0x7F,             // Contrast control
    0xD9, 0x22,             // Pre-charge period
    0xDB, 0x35,             // VCOM deselect level
    0xA4,                   // Entire display ON follows RAM
    0xA6,                   // Normal display (A7 = inverse)
    // 0xAF,                   // Display ON
    0xFF,                   // END
};
*/
/*
static esp_err_t panel_sh1106_init(esp_lcd_panel_t *panel)
{
    sh1106_panel_t *sh1106 = __containerof(panel, sh1106_panel_t, base);
    esp_lcd_panel_io_handle_t io = sh1106->io;
    ESP_LOGI(TAG, "Initializing SH1106 panel...");
    int cmd = 0;
    while (vendor_specific_init[cmd] != 0xff) {
        esp_err_t ret = esp_lcd_panel_io_tx_param(io, LCD_SH1106_I2C_CMD, (uint8_t[]) {
            vendor_specific_init[cmd]
        }, 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        if (ret != ESP_OK) {
            ESP_LOGE(TAG, "Failed to send init command 0x%02X: %s", vendor_specific_init[cmd], esp_err_to_name(ret));
            return ret;
        }
        cmd++;
    }
    ESP_LOGI(TAG, "SH1106 panel initialized successfully");
    return ESP_OK;
}
*/

static int cmd_param_len(uint8_t cmd) {
    switch (cmd) {
        case 0xD5: case 0xA8: case 0xD3:
        case 0x8D: case 0x20: case 0xDA:
        case 0x81: case 0xD9: case 0xDB:
            return 1; // ці команди мають 1 параметр
        default:
            return 0; // інші без параметрів
    }
}

static esp_err_t panel_sh1106_init(esp_lcd_panel_t *panel)
{
    sh1106_panel_t *sh = __containerof(panel, sh1106_panel_t, base);
    esp_lcd_panel_io_handle_t io = sh->io;

    const uint8_t *p = vendor_specific_init;
    while (*p != 0xFF) {
        int n = cmd_param_len(*p);
        ESP_RETURN_ON_ERROR(
            esp_lcd_panel_io_tx_param(io, 0x00 /*CMD*/, (uint8_t*)p, n + 1),
            TAG, "init tx"
        );
        p += (n + 1);
        vTaskDelay(pdMS_TO_TICKS(1));
    }

    ESP_LOGI(TAG, "Init done (SSD1306-style + page mode)");
    return ESP_OK;
}


static esp_err_t panel_sh1106_draw_bitmap(esp_lcd_panel_t *panel, int x_start, int y_start, int x_end, int y_end, const void *color_data)
{
    sh1106_panel_t *sh1106 = __containerof(panel, sh1106_panel_t, base);
    assert((x_start < x_end) && (y_start < y_end) && "start position must be smaller than end position");
    esp_lcd_panel_io_handle_t io = sh1106->io;

    uint8_t column_low = 0;
    uint8_t column_high = 0;
    uint8_t row_start = 0, row_end = 0;
    const uint16_t *ptr;
    uint32_t size = 0;

    // adding extra gap
    x_start += sh1106->x_gap;
    x_end += sh1106->x_gap;
    y_start += sh1106->y_gap;
    y_end += sh1106->y_gap;

    if (sh1106->swap_axes) {
        int x = x_start;
        x_start = y_start;
        y_start = x;
        x = x_end;
        x_end = y_end;
        y_end = x;
    }

    row_start = y_start >> 3;
    row_end = y_end >> 3;

    column_low = x_start & 0x0F;
    column_high = (x_start >> 4) & 0x0F;

    size = (x_end - x_start);

    for (int i = row_start; i < row_end; i++) {
        /* Start column */
        esp_lcd_panel_io_tx_param(io, LCD_SH1106_I2C_CMD, (uint8_t[]) {
            0x10 | column_high
        }, 1);
        esp_lcd_panel_io_tx_param(io, LCD_SH1106_I2C_CMD, (uint8_t[]) {
            0x00 | column_low
        }, 1);
        /* Page */
        esp_lcd_panel_io_tx_param(io, LCD_SH1106_I2C_CMD, (uint8_t[]) {
            0xB0 | i
        }, 1);

        ptr = color_data + i * x_end;
        esp_lcd_panel_io_tx_color(io, LCD_SH1106_I2C_RAM, (uint8_t *)ptr, size);
    }

    return ESP_OK;
}

static esp_err_t panel_sh1106_invert_color(esp_lcd_panel_t *panel, bool invert_color_data)
{
    sh1106_panel_t *sh1106 = __containerof(panel, sh1106_panel_t, base);
    esp_lcd_panel_io_handle_t io = sh1106->io;

    if (invert_color_data) {
        esp_lcd_panel_io_tx_param(io, LCD_SH1106_I2C_CMD, (uint8_t[]) {
            (LCD_SH1106_PARAM_INVERT_COLOR)
        }, 1);
    } else {
        esp_lcd_panel_io_tx_param(io, LCD_SH1106_I2C_CMD, (uint8_t[]) {
            (LCD_SH1106_PARAM_INVERT_COLOR | 0x01)
        }, 1);
    }
    return ESP_OK;
}

static esp_err_t panel_sh1106_mirror(esp_lcd_panel_t *panel, bool mirror_x, bool mirror_y)
{
    sh1106_panel_t *sh1106 = __containerof(panel, sh1106_panel_t, base);
    esp_lcd_panel_io_handle_t io = sh1106->io;
    uint8_t param_x = (LCD_SH1106_PARAM_MIRROR_X);
    uint8_t param_y = (LCD_SH1106_PARAM_MIRROR_Y | 0x07);

    if (mirror_x) {
        param_x = (LCD_SH1106_PARAM_MIRROR_X | 0x01);
    }
    if (mirror_y) {
        param_y = (LCD_SH1106_PARAM_MIRROR_Y | 0x08);
    }

    esp_lcd_panel_io_tx_param(io, LCD_SH1106_I2C_CMD, (uint8_t[]) {
        param_x
    }, 1);
    esp_lcd_panel_io_tx_param(io, LCD_SH1106_I2C_CMD, (uint8_t[]) {
        param_y
    }, 1);

    return ESP_OK;
}

static esp_err_t panel_sh1106_swap_xy(esp_lcd_panel_t *panel, bool swap_axes)
{
    sh1106_panel_t *sh1106 = __containerof(panel, sh1106_panel_t, base);
    sh1106->swap_axes = swap_axes;

    return ESP_OK;
}

static esp_err_t panel_sh1106_set_gap(esp_lcd_panel_t *panel, int x_gap, int y_gap)
{
    sh1106_panel_t *sh1106 = __containerof(panel, sh1106_panel_t, base);
    sh1106->x_gap = x_gap;
    sh1106->y_gap = y_gap;
    return ESP_OK;
}

static esp_err_t panel_sh1106_disp_on_off(esp_lcd_panel_t *panel, bool on_off)
{
    sh1106_panel_t *sh1106 = __containerof(panel, sh1106_panel_t, base);
    esp_lcd_panel_io_handle_t io = sh1106->io;
    uint8_t param = 0;

#if ESP_IDF_VERSION < ESP_IDF_VERSION_VAL(5, 0, 0)
    on_off = !on_off;
#endif

    if (on_off) {
        param = (LCD_SH1106_PARAM_ONOFF | 0x01);
    } else {
        param = LCD_SH1106_PARAM_ONOFF;
    }

    esp_lcd_panel_io_tx_param(io, LCD_SH1106_I2C_CMD, (uint8_t[]) {
        param
    }, 1);

    return ESP_OK;
}
