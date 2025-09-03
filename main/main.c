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
#include "esp_random.h"
#include "esp_lvgl_port.h"
#include "esp_lcd_sh1107.h"
#include "lcd_sh1106.h"
#include "include/display_update.h"
#include "include/main.h"
#include "sht41.h"

static const char *TAG = "example";

extern void example_lvgl_demo_ui(lv_disp_t *disp);

static esp_err_t init_i2c_bus(i2c_master_bus_handle_t *i2c_bus, i2c_port_t i2c_port, gpio_num_t sda_pin, gpio_num_t scl_pin);
static esp_err_t init_i2c_sh1107_display(i2c_master_bus_handle_t i2c_bus);
static esp_err_t init_i2c_sh1106_display(i2c_master_bus_handle_t i2c_bus);

static esp_err_t init_sh1107_panel();
static esp_err_t init_sh1106_panel();
static void sensor_data_task(void *pvParameters);

static i2c_master_bus_handle_t i2c_bus_0;
static i2c_master_bus_handle_t i2c_bus_1;  // Commented out as not used

static esp_lcd_panel_io_handle_t sh1107_io_handle;
static esp_lcd_panel_handle_t sh1107_panel_handle;

static esp_lcd_panel_io_handle_t sh1106_io_handle;
static esp_lcd_panel_handle_t sh1106_panel_handle;

static i2c_master_dev_handle_t sht41_dev_handle;


void app_main(void)
{
    ESP_LOGI(TAG, "Initialize I2C bus 0");
    ESP_ERROR_CHECK(init_i2c_bus(&i2c_bus_0, I2C_NUM_0, SH1107_I2C_SDA_PIN, SH1107_I2C_SCL_PIN));

    ESP_LOGI(TAG, "Initialize I2C bus 1");
    ESP_ERROR_CHECK(init_i2c_bus(&i2c_bus_1, I2C_NUM_1, SH1106_I2C_SDA_PIN, SH1106_I2C_SCL_PIN));

    ESP_LOGI(TAG, "Initialize SH1107 Display");
    ESP_ERROR_CHECK(init_i2c_sh1107_display(i2c_bus_0));

    ESP_LOGI(TAG, "Initialize SH1106 Display");
    ESP_ERROR_CHECK(init_i2c_sh1106_display(i2c_bus_1));

    ESP_LOGI(TAG, "Initialize SHT41");
    ESP_ERROR_CHECK(init_handle_sht41(&sht41_dev_handle, i2c_bus_0, SHT41_I2C_ADDR, I2C_CLK_HZ));

    /* Configure SH1107 with proper display offset for 128x128 */
    // esp_lcd_panel_sh1107_config_t sh1107_config = {
    //     .display_offset = 0x00,  /* 0x00 for 128x128 displays, 0x60 default */
    // };

    ESP_LOGI(TAG, "Initialize SH1107 Panel");
    ESP_ERROR_CHECK(init_sh1107_panel());

    ESP_LOGI(TAG, "Initialize SH1106 Panel");
    ESP_ERROR_CHECK(init_sh1106_panel());

    ESP_ERROR_CHECK(esp_lcd_panel_reset(sh1107_panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(sh1107_panel_handle));

    ESP_ERROR_CHECK(esp_lcd_panel_reset(sh1106_panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(sh1106_panel_handle));
    
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(sh1107_panel_handle, true));
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(sh1106_panel_handle, true));

    ESP_ERROR_CHECK(esp_lcd_panel_invert_color(sh1107_panel_handle, true));
    ESP_ERROR_CHECK(esp_lcd_panel_invert_color(sh1106_panel_handle, true));

    ESP_LOGI(TAG, "Initialize LVGL for SH1107");
    const lvgl_port_cfg_t lvgl_cfg = ESP_LVGL_PORT_INIT_CONFIG();
    lvgl_port_init(&lvgl_cfg);

    const lvgl_port_display_cfg_t disp_cfg = {
        .io_handle = sh1107_io_handle,
        .panel_handle = sh1107_panel_handle,

        .buffer_size = SH1107_LCD_H_RES * SH1107_LCD_V_RES,
        .hres = SH1107_LCD_H_RES,
        .vres = SH1107_LCD_V_RES,
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

    
    // SH1106 має зсув пам'яті - встановлюємо gap для центрування
    ESP_ERROR_CHECK(esp_lcd_panel_set_gap(sh1106_panel_handle, 2, 0));
    
    const lvgl_port_display_cfg_t disp_cfg2 = {
        .io_handle = sh1106_io_handle,
        .panel_handle = sh1106_panel_handle,
        .buffer_size = SH1106_LCD_H_RES * SH1106_LCD_V_RES / 8,  // 1 біт на піксель = 8 пікселів на байт
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
        // lv_obj_t *label2 = lv_label_create(lv_disp_get_scr_act(disp2));
        // lv_label_set_text(label2, "Hello SH1106!");
        // lv_obj_center(label2);
        // lvgl_port_unlock();
        /* Rotation of the screen */
        lv_disp_set_rotation(disp2, LV_DISPLAY_ROTATION_0);

        example_lvgl_demo_ui(disp2);
        // Release the mutex
        lvgl_port_unlock();
    }

    // ESP_LOGI(TAG, "Display LVGL Scroll Text");
    // // Lock the mutex due to the LVGL APIs are not thread-safe
    // if (lvgl_port_lock(0)) {
    //     /* Rotation of the screen */
    //     lv_disp_set_rotation(disp, LV_DISPLAY_ROTATION_0);

    //     example_lvgl_demo_ui(disp);
    //     // Release the mutex
    //     lvgl_port_unlock();
    // }
    
    // /* Create task to simulate sensor data updates */
    xTaskCreate(sensor_data_task, "sensor_data", 4096, NULL, 5, NULL);
}

/* Task to simulate sensor data and update display */
static void sensor_data_task(void *pvParameters)
{
    float temperature;
    float humidity;

    while (1) {
        /* Better simulation with more realistic behavior */
        sht41_read(&temperature, &humidity, sht41_dev_handle);
        
        /* Update display with new values */
        if (lvgl_port_lock(0)) {
            update_temperature_display(temperature);
            update_humidity_display(humidity);
            // update_pressure_display(pressure);
            lvgl_port_unlock();
        }
        
        // ESP_LOGI(TAG, "Sensor data - Temp: %.1f°C, Hum: %.1f%%, Press: %.0fhPa", 
        //          temperature, humidity, pressure);
        
        /* Update every 2 seconds */
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

esp_err_t init_i2c_bus(i2c_master_bus_handle_t *i2c_bus, i2c_port_t i2c_port, gpio_num_t sda_pin, gpio_num_t scl_pin)
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

esp_err_t init_i2c_sh1107_display(i2c_master_bus_handle_t i2c_bus)
{
    esp_lcd_panel_io_i2c_config_t io_config = {
        .dev_addr = SH1107_I2C_ADDR,
        .scl_speed_hz = I2C_CLK_HZ,
        .control_phase_bytes = 1,               // According to SH1107 datasheet
        .lcd_cmd_bits = SH1107_LCD_CMD_BITS,   // According to SH1107 datasheet
        .lcd_param_bits = SH1107_LCD_PARAM_BITS, // According to SH1107 datasheet

        .dc_bit_offset = 0,                     // According to SH1107 datasheet
        .flags =
        {
            .disable_control_phase = 1,
        }
    };
    return esp_lcd_new_panel_io_i2c(i2c_bus, &io_config, &sh1107_io_handle);
}

esp_err_t init_i2c_sh1106_display(i2c_master_bus_handle_t i2c_bus)
{
    esp_lcd_panel_io_i2c_config_t io_config = {
        .dev_addr = SH1106_I2C_ADDR,
        .scl_speed_hz = I2C_CLK_HZ,
        .control_phase_bytes = 1,               // According to SH1106 datasheet
        .lcd_cmd_bits = SH1106_LCD_CMD_BITS,   // According to SH1106 datasheet
        .lcd_param_bits = SH1106_LCD_PARAM_BITS, // According to SH1106 datasheet

        .dc_bit_offset = 0,                     // According to SH1106 datasheet
        .flags =
        {
            .disable_control_phase = 1,
        }
    };
    return esp_lcd_new_panel_io_i2c(i2c_bus, &io_config, &sh1106_io_handle);
}


esp_err_t init_sh1107_panel()
{
    esp_lcd_panel_dev_config_t panel_config = {
        .bits_per_pixel = 1,
        .reset_gpio_num = SH1107_RST_PIN,
    };

    return esp_lcd_new_panel_sh1107(sh1107_io_handle, &panel_config, &sh1107_panel_handle);
}

esp_err_t init_sh1106_panel()
{
    esp_lcd_panel_dev_config_t panel_config = {
        .bits_per_pixel = 1,
        .reset_gpio_num = SH1106_RST_PIN,
    };

    return esp_lcd_new_panel_sh1106(sh1106_io_handle, &panel_config, &sh1106_panel_handle);
}
