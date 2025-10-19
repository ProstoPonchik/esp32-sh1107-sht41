#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "driver/i2c_master.h"
#include "esp_err.h"
#include "esp_log.h"
#include "lvgl.h"
#include "driver/gpio.h"
#include "esp_random.h"
#include "esp_lvgl_port.h"
#include "esp_lcd_sh1107.h"
#include "lcd_sh1106.h"
#include "include/display_update.h"
#include "include/main.h"
#include "sht41.h"
#include "bme680.h"
#include "sdspi.h"

static const char *TAG = "example";

extern void lvgl_ui_sh1106(lv_disp_t *disp);
extern void lvgl_ui_sh1107(lv_disp_t *disp);

// Function declarations
static esp_err_t init_i2c_bus(i2c_master_bus_handle_t *i2c_bus, i2c_port_t i2c_port, gpio_num_t sda_pin, gpio_num_t scl_pin);
static esp_err_t init_i2c_sh1107_display(i2c_master_bus_handle_t i2c_bus);
static esp_err_t init_i2c_sh1106_display(i2c_master_bus_handle_t i2c_bus);
static esp_err_t init_sh1107_panel(void);
static esp_err_t init_sh1106_panel(void);
static void sensor_data_task(void *pvParameters);

// Global variables
static i2c_master_bus_handle_t i2c_bus_0;
static i2c_master_bus_handle_t i2c_bus_1;

static esp_lcd_panel_io_handle_t sh1107_io_handle;
static esp_lcd_panel_handle_t sh1107_panel_handle;

static esp_lcd_panel_io_handle_t sh1106_io_handle;
static esp_lcd_panel_handle_t sh1106_panel_handle;

static i2c_master_dev_handle_t sht41_dev_handle;

static i2c_master_dev_handle_t bme680_dev_handle;

void app_main(void)
{
    gpio_set_direction(LED_PIN_1, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_PIN_2, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_PIN_3, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_PIN_4, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_PIN_5, GPIO_MODE_OUTPUT);

    ESP_LOGI(TAG, "Initialize I2C bus 0");
    ESP_ERROR_CHECK(init_i2c_bus(&i2c_bus_0, I2C_NUM_0, I2C_SDA_PIN_0, I2C_SCL_PIN_0));

    ESP_LOGI(TAG, "Initialize SH1107 Display");
    ESP_ERROR_CHECK(init_i2c_sh1107_display(i2c_bus_0));

    ESP_LOGI(TAG, "Initialize SHT41");
    ESP_ERROR_CHECK(init_handle_sht41(&sht41_dev_handle, i2c_bus_0, SHT41_I2C_ADDR, I2C_CLK_HZ));

    vTaskDelay(pdMS_TO_TICKS(10));

    ESP_ERROR_CHECK(sht41_soft_reset(sht41_dev_handle));

    vTaskDelay(pdMS_TO_TICKS(10));

    uint32_t serial_number = 0;
    ESP_ERROR_CHECK(sht41_serial_number(sht41_dev_handle, &serial_number));
    ESP_LOGI(TAG, "SHT41 SN: 0x%08X  (%04X-%04X)", serial_number, (uint16_t)(serial_number >> 16), (uint16_t)serial_number);

    ESP_LOGI(TAG, "Initialize SH1107 Panel");
    ESP_ERROR_CHECK(init_sh1107_panel());

    ESP_ERROR_CHECK(esp_lcd_panel_reset(sh1107_panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(sh1107_panel_handle));

    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(sh1107_panel_handle, true));
    ESP_ERROR_CHECK(esp_lcd_panel_invert_color(sh1107_panel_handle, true));
    
    ESP_LOGI(TAG, "Initialize I2C bus 1");
    ESP_ERROR_CHECK(init_i2c_bus(&i2c_bus_1, I2C_NUM_1, I2C_SDA_PIN_1, I2C_SCL_PIN_1));

    ESP_LOGI(TAG, "Initialize SH1106 Display");
    ESP_ERROR_CHECK(init_i2c_sh1106_display(i2c_bus_1));

    ESP_LOGI(TAG, "Initialize SH1106 Panel");
    ESP_ERROR_CHECK(init_sh1106_panel());

    ESP_ERROR_CHECK(esp_lcd_panel_reset(sh1106_panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(sh1106_panel_handle));

    // ESP_ERROR_CHECK(esp_lcd_panel_invert_color(sh1106_panel_handle, false)); // SSD1306 без інверсії

    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(sh1106_panel_handle, true));

    // ESP_LOGI(TAG, "Initialize BME680");
    // ESP_ERROR_CHECK(init_handle_bme680(&bme680_dev_handle, i2c_bus_1, BME680_I2C_ADDR, I2C_CLK_HZ));
    
    // SD Card initialization with diagnostics
    ESP_LOGI(TAG, "Initialize SD Card");
    mount_sd_over_spi();

    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0xAE}, 1); // Display off
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0x8D}, 1); // Charge pump
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0x14}, 1); // Enable
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0xA8}, 1); // Multiplex
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0x3F}, 1); // 64 lines
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0xD3}, 1); // Display offset
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0x00}, 1); // No offset
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0x40}, 1); // Start line 0
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0xA1}, 1); // Segment remap
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0xC8}, 1); // COM scan
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0xDA}, 1); // COM pins
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0x12}, 1); // Alt COM
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0x81}, 1); // Contrast
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0xFF}, 1); // MAX
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0xA4}, 1); // Resume RAM
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0xA6}, 1); // Normal display
    // esp_lcd_panel_io_tx_param(sh1106_io_handle, 0x00, (uint8_t[]){0xAF}, 1); // Display ON

    vTaskDelay(pdMS_TO_TICKS(100));


    ESP_LOGI(TAG, "Initialize LVGL");
    const lvgl_port_cfg_t lvgl_cfg = ESP_LVGL_PORT_INIT_CONFIG();
    lvgl_port_init(&lvgl_cfg);

    // SH1107 дисплей (основний)
    const lvgl_port_display_cfg_t disp_cfg = {
        .io_handle = sh1107_io_handle,
        .panel_handle = sh1107_panel_handle,
        .buffer_size = SH1107_LCD_H_RES * SH1107_LCD_V_RES,
        .hres = SH1107_LCD_H_RES,
        .vres = SH1107_LCD_V_RES,
        .double_buffer = false,
        .monochrome = true,
        .color_format = LV_COLOR_FORMAT_I1,
        .rotation = { .swap_xy = false, .mirror_x = false, .mirror_y = false },
        .flags = { .swap_bytes = false, .sw_rotate = false }
    };
    lv_disp_t *disp = lvgl_port_add_disp(&disp_cfg);
    
    // SSD1306 дисплей (другий) - тепер працює після правильної ініціалізації!
    ESP_LOGI(TAG, "Adding SSD1306 to LVGL");
    ESP_ERROR_CHECK(esp_lcd_panel_set_gap(sh1106_panel_handle, 0, 0)); // SSD1306 не потребує зсуву
    
    const lvgl_port_display_cfg_t disp_cfg2 = {
        .io_handle = sh1106_io_handle,
        .panel_handle = sh1106_panel_handle,
        .buffer_size = SH1106_LCD_H_RES * SH1106_LCD_V_RES,
        .hres = SH1106_LCD_H_RES,
        .vres = SH1106_LCD_V_RES,
        .double_buffer = false,
        .monochrome = true,
        .color_format = LV_COLOR_FORMAT_I1,
        .rotation = { .swap_xy = false, .mirror_x = false, .mirror_y = false },
        .flags = { .swap_bytes = false, .sw_rotate = false }
    };
    lv_disp_t *disp2 = lvgl_port_add_disp(&disp_cfg2);

    if (lvgl_port_lock(0)) {
        // Налаштування SH1107
        lv_disp_set_rotation(disp, LV_DISPLAY_ROTATION_0);
        lvgl_ui_sh1106(disp);

        // Налаштування SH1106 - тепер увімкнено!
        ESP_LOGI(TAG, "Setting up SH1106 UI");
        lv_disp_set_rotation(disp2, LV_DISPLAY_ROTATION_180);
        lvgl_ui_sh1107(disp2);
        
        // // ФОРСУЄМО обертання після LVGL ініціалізації
        // ESP_LOGI(TAG, "Forcing SSD1306 orientation after LVGL...");

        // lv_obj_t *label2 = lv_label_create(lv_disp_get_scr_act(disp2));
        // lv_obj_set_width(label2, 128);
        // lv_obj_set_style_text_align(label2, LV_TEXT_ALIGN_CENTER, 0);
        // lv_obj_set_style_text_font(label2, &lv_font_jb_14, 0);
        // lv_label_set_text(label2, "Test Andriy\nWorking!");
        // lv_obj_center(label2);
        
        lvgl_port_unlock();
    }
    
    /* Create task to simulate sensor data updates */
    xTaskCreate(sensor_data_task, "sensor_data", 4096, NULL, 5, NULL);
}

/* Task to simulate sensor data and update display */
static void sensor_data_task(void *pvParameters)
{
    float temperature;
    float humidity;

    while (1) {
        // gpio_set_level(LED_PIN_1, 1);
        // vTaskDelay(pdMS_TO_TICKS(300));
        // gpio_set_level(LED_PIN_1, 0);

        // gpio_set_level(LED_PIN_2, 1);
        // vTaskDelay(pdMS_TO_TICKS(300));
        // gpio_set_level(LED_PIN_2, 0);

        // gpio_set_level(LED_PIN_3, 1);
        // vTaskDelay(pdMS_TO_TICKS(300));
        // gpio_set_level(LED_PIN_3, 0);

        // gpio_set_level(LED_PIN_4, 1);
        // vTaskDelay(pdMS_TO_TICKS(300));
        // gpio_set_level(LED_PIN_4, 0);

        // gpio_set_level(LED_PIN_5, 1);
        // vTaskDelay(pdMS_TO_TICKS(300));
        // gpio_set_level(LED_PIN_5, 0);
        /* Better simulation with more realistic behavior */
        sht41_tmp_hmd_read(&temperature, &humidity, sht41_dev_handle);
        
        /* Update display with new values */
        if (lvgl_port_lock(0)) {
            update_temperature_display(temperature);
            update_humidity_display(humidity);
            lvgl_port_unlock();
        }
        /* Update every 2 seconds */
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

static esp_err_t init_i2c_bus(i2c_master_bus_handle_t *i2c_bus, i2c_port_t i2c_port, gpio_num_t sda_pin, gpio_num_t scl_pin)
{
    i2c_master_bus_config_t bus_config = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .i2c_port = i2c_port,
        .sda_io_num = sda_pin,
        .scl_io_num = scl_pin,
        .flags.enable_internal_pullup = true,
    };
    return i2c_new_master_bus(&bus_config, i2c_bus);
}

static esp_err_t init_i2c_sh1107_display(i2c_master_bus_handle_t i2c_bus)
{
    esp_lcd_panel_io_i2c_config_t io_config = {
        .dev_addr = SH1107_I2C_ADDR,
        .scl_speed_hz = I2C_CLK_HZ,
        .control_phase_bytes = 1,
        .lcd_cmd_bits = SH1107_LCD_CMD_BITS,
        .lcd_param_bits = SH1107_LCD_PARAM_BITS,
        .dc_bit_offset = 0,
        .flags = { .disable_control_phase = 1 }
    };
    return esp_lcd_new_panel_io_i2c(i2c_bus, &io_config, &sh1107_io_handle);
}

static esp_err_t init_i2c_sh1106_display(i2c_master_bus_handle_t i2c_bus)
{
    esp_lcd_panel_io_i2c_config_t io_config = {
        .dev_addr = SH1106_I2C_ADDR,
        .scl_speed_hz = I2C_CLK_HZ,
        .control_phase_bytes = 1,
        .lcd_cmd_bits = SH1106_LCD_CMD_BITS,
        .lcd_param_bits = SH1106_LCD_PARAM_BITS,
        .dc_bit_offset = 0,
        .flags = { .disable_control_phase = 1 }
    };
    return esp_lcd_new_panel_io_i2c(i2c_bus, &io_config, &sh1106_io_handle);
}

static esp_err_t init_sh1107_panel(void)
{
    esp_lcd_panel_dev_config_t panel_config = {
        .bits_per_pixel = 1,
        .reset_gpio_num = SH1107_RST_PIN,
    };
    return esp_lcd_new_panel_sh1107(sh1107_io_handle, &panel_config, &sh1107_panel_handle);
}

static esp_err_t init_sh1106_panel(void)
{
    esp_lcd_panel_dev_config_t panel_config = {
        .bits_per_pixel = 1,
        .reset_gpio_num = SH1106_RST_PIN,
    };
    return esp_lcd_new_panel_sh1106(sh1106_io_handle, &panel_config, &sh1106_panel_handle);
}