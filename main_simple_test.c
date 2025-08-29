/**
 * @file main_simple_test.c
 * @brief Simple test version to debug display issues
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_check.h"
#include "esp_system.h"

/* For simple test - direct includes */
#include "driver/i2c_master.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_sh1107.h"
#include "esp_lvgl_port.h"
#include "lvgl.h"

static const char *TAG = "simple_test";

/* Simple test configuration */
#define TEST_I2C_MASTER_PORT         I2C_NUM_0
#define TEST_I2C_MASTER_FREQ_HZ      (400 * 1000)
#define TEST_I2C_MASTER_SDA_IO       GPIO_NUM_17
#define TEST_I2C_MASTER_SCL_IO       GPIO_NUM_18
#define TEST_SH1107_I2C_ADDR         0x3C
#define TEST_SH1107_LCD_H_RES        128
#define TEST_SH1107_LCD_V_RES        128

static i2c_master_bus_handle_t s_i2c_bus_handle = NULL;
static esp_lcd_panel_io_handle_t s_sh1107_io_handle = NULL;
static esp_lcd_panel_handle_t s_sh1107_panel_handle = NULL;

static esp_err_t test_init_i2c_bus(void)
{
    ESP_LOGI(TAG, "Initializing I2C bus");
    
    i2c_master_bus_config_t bus_config = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .i2c_port = TEST_I2C_MASTER_PORT,
        .scl_io_num = TEST_I2C_MASTER_SCL_IO,
        .sda_io_num = TEST_I2C_MASTER_SDA_IO,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };

    esp_err_t ret = i2c_new_master_bus(&bus_config, &s_i2c_bus_handle);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "I2C bus init failed: %s", esp_err_to_name(ret));
        return ret;
    }

    ESP_LOGI(TAG, "I2C bus initialized successfully");
    return ESP_OK;
}

static esp_err_t test_probe_display(void)
{
    ESP_LOGI(TAG, "Probing display at address 0x%02X", TEST_SH1107_I2C_ADDR);
    
    esp_err_t ret = i2c_master_probe(s_i2c_bus_handle, TEST_SH1107_I2C_ADDR, pdMS_TO_TICKS(1000));
    if (ret == ESP_OK) {
        ESP_LOGI(TAG, "Display found at address 0x%02X", TEST_SH1107_I2C_ADDR);
    } else {
        ESP_LOGE(TAG, "Display NOT found at address 0x%02X: %s", TEST_SH1107_I2C_ADDR, esp_err_to_name(ret));
    }
    
    return ret;
}

static esp_err_t test_init_display_io(void)
{
    ESP_LOGI(TAG, "Initializing display I/O");
    
    esp_lcd_panel_io_i2c_config_t io_config = {
        .dev_addr = TEST_SH1107_I2C_ADDR,
        .scl_speed_hz = TEST_I2C_MASTER_FREQ_HZ,
        .control_phase_bytes = 1,
        .lcd_cmd_bits = 8,
        .lcd_param_bits = 8,
        .dc_bit_offset = 0,
        .flags = {
            .disable_control_phase = 1,
        }
    };

    esp_err_t ret = esp_lcd_new_panel_io_i2c(s_i2c_bus_handle, &io_config, &s_sh1107_io_handle);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Display I/O init failed: %s", esp_err_to_name(ret));
        return ret;
    }

    ESP_LOGI(TAG, "Display I/O initialized successfully");
    return ESP_OK;
}

static esp_err_t test_init_display_panel(void)
{
    ESP_LOGI(TAG, "Initializing display panel");
    
    esp_lcd_panel_dev_config_t panel_config = {
        .bits_per_pixel = 1,
        .reset_gpio_num = GPIO_NUM_NC,
    };

    esp_lcd_panel_sh1107_config_t sh1107_config = {
        .display_offset = 0x00,
    };
    panel_config.vendor_config = &sh1107_config;

    esp_err_t ret = esp_lcd_new_panel_sh1107(s_sh1107_io_handle, &panel_config, &s_sh1107_panel_handle);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Display panel creation failed: %s", esp_err_to_name(ret));
        return ret;
    }

    /* Reset and initialize */
    ESP_LOGI(TAG, "Resetting display panel");
    ret = esp_lcd_panel_reset(s_sh1107_panel_handle);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Display reset failed: %s", esp_err_to_name(ret));
        return ret;
    }

    ESP_LOGI(TAG, "Initializing display panel");
    ret = esp_lcd_panel_init(s_sh1107_panel_handle);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Display init failed: %s", esp_err_to_name(ret));
        return ret;
    }

    ESP_LOGI(TAG, "Turning on display");
    ret = esp_lcd_panel_disp_on_off(s_sh1107_panel_handle, true);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Display turn on failed: %s", esp_err_to_name(ret));
        return ret;
    }

    ESP_LOGI(TAG, "Setting display invert");
    ret = esp_lcd_panel_invert_color(s_sh1107_panel_handle, true);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Display invert failed: %s", esp_err_to_name(ret));
        return ret;
    }

    ESP_LOGI(TAG, "Display panel initialized successfully");
    return ESP_OK;
}

static esp_err_t test_init_lvgl(void)
{
    ESP_LOGI(TAG, "Initializing LVGL");
    
    const lvgl_port_cfg_t lvgl_cfg = ESP_LVGL_PORT_INIT_CONFIG();
    esp_err_t ret = lvgl_port_init(&lvgl_cfg);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "LVGL port init failed: %s", esp_err_to_name(ret));
        return ret;
    }

    const lvgl_port_display_cfg_t disp_cfg = {
        .io_handle = s_sh1107_io_handle,
        .panel_handle = s_sh1107_panel_handle,
        .buffer_size = TEST_SH1107_LCD_H_RES * TEST_SH1107_LCD_V_RES,
        .hres = TEST_SH1107_LCD_H_RES,
        .vres = TEST_SH1107_LCD_V_RES,
        .double_buffer = false,
        .monochrome = true,
        .color_format = LV_COLOR_FORMAT_I1,
        .rotation = {
            .swap_xy = false,
            .mirror_x = false,
            .mirror_y = false,
        },
        .flags = {
            .swap_bytes = false,
            .sw_rotate = false,
        }
    };

    lv_disp_t *disp = lvgl_port_add_disp(&disp_cfg);
    if (disp == NULL) {
        ESP_LOGE(TAG, "LVGL display add failed");
        return ESP_FAIL;
    }

    ESP_LOGI(TAG, "LVGL initialized successfully");
    return ESP_OK;
}

static void test_create_simple_ui(void)
{
    ESP_LOGI(TAG, "Creating simple test UI");
    
    if (lvgl_port_lock(pdMS_TO_TICKS(1000))) {
        lv_obj_t *scr = lv_scr_act();
        
        /* Create a simple label */
        lv_obj_t *label = lv_label_create(scr);
        lv_label_set_text(label, "TEST\nDISPLAY\nWORKS!");
        lv_obj_center(label);
        
        /* Set white text on black background */
        lv_obj_set_style_text_color(label, lv_color_white(), LV_PART_MAIN);
        lv_obj_set_style_bg_color(scr, lv_color_black(), LV_PART_MAIN);
        
        lvgl_port_unlock();
        ESP_LOGI(TAG, "Test UI created");
    } else {
        ESP_LOGE(TAG, "Failed to lock LVGL mutex");
    }
}

void app_main(void)
{
    ESP_LOGI(TAG, "Starting simple display test");
    ESP_LOGI(TAG, "ESP-IDF Version: %s", esp_get_idf_version());
    
    esp_err_t ret = ESP_OK;
    
    /* Step by step initialization with detailed logging */
    
    ESP_LOGI(TAG, "Step 1: Initialize I2C bus");
    ret = test_init_i2c_bus();
    if (ret != ESP_OK) goto error;
    
    ESP_LOGI(TAG, "Step 2: Probe display");
    ret = test_probe_display();
    if (ret != ESP_OK) goto error;
    
    ESP_LOGI(TAG, "Step 3: Initialize display I/O");
    ret = test_init_display_io();
    if (ret != ESP_OK) goto error;
    
    ESP_LOGI(TAG, "Step 4: Initialize display panel");
    ret = test_init_display_panel();
    if (ret != ESP_OK) goto error;
    
    ESP_LOGI(TAG, "Step 5: Initialize LVGL");
    ret = test_init_lvgl();
    if (ret != ESP_OK) goto error;
    
    ESP_LOGI(TAG, "Step 6: Create test UI");
    test_create_simple_ui();
    
    ESP_LOGI(TAG, "Test completed successfully!");
    ESP_LOGI(TAG, "Free heap: %"PRIu32" bytes", esp_get_free_heap_size());
    
    /* Simple loop to keep the display active */
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(5000));
        ESP_LOGI(TAG, "Display test running... Free heap: %"PRIu32" bytes", esp_get_free_heap_size());
    }

error:
    ESP_LOGE(TAG, "Test failed at initialization step");
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
