/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "lvgl.h"
#include "esp_log.h"
#include "stdio.h"

static const char *TAG = "LVGL_UI";

/* Global labels for sensor data - accessible from other files */
static lv_obj_t *temp_label = NULL;
static lv_obj_t *humidity_label = NULL;
static lv_obj_t *pressure_label = NULL;

void example_lvgl_demo_ui(lv_disp_t *disp)
{
    lv_obj_t *scr = lv_disp_get_scr_act(disp);
    
    /* Remove all padding and margins from screen */
    lv_obj_set_style_pad_all(scr, 0, LV_PART_MAIN);
    lv_obj_set_style_margin_all(scr, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(scr, 0, LV_PART_MAIN);
    
    /* Create temperature label */
    temp_label = lv_label_create(scr);
    lv_label_set_text(temp_label, "Temp: --.-°C");
    lv_obj_set_pos(temp_label, 0, 0);
    lv_obj_set_width(temp_label, 128);
    
    /* Create humidity label */
    humidity_label = lv_label_create(scr);
    lv_label_set_text(humidity_label, "Hum: --.-%");
    lv_obj_set_pos(humidity_label, 0, 20);
    lv_obj_set_width(humidity_label, 128);
    
    // /* Create pressure label */
    // pressure_label = lv_label_create(scr);
    // lv_label_set_text(pressure_label, "Press: ----hPa");
    // lv_obj_set_pos(pressure_label, 0, 40);
    // lv_obj_set_width(pressure_label, 128);
    
    /* Remove padding from all labels */
    lv_obj_set_style_pad_all(temp_label, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(humidity_label, 0, LV_PART_MAIN);
    // lv_obj_set_style_pad_all(pressure_label, 0, LV_PART_MAIN);
    
    ESP_LOGI(TAG, "Created sensor data display interface");
}

/* Function to update temperature display */
void update_temperature_display(float temperature)
{
    if (temp_label != NULL) {
        lv_label_set_text_fmt(temp_label, "Temp: %.1f°C", temperature);
    }
}

/* Function to update humidity display */
void update_humidity_display(float humidity)
{
    if (humidity_label != NULL) {
        char hum_str[32];
        snprintf(hum_str, sizeof(hum_str), "Hum: %.1f%%", humidity);
        lv_label_set_text(humidity_label, hum_str);
    }
}

/* Function to update pressure display */
void update_pressure_display(float pressure)
{
    if (pressure_label != NULL) {
        char press_str[32];
        snprintf(press_str, sizeof(press_str), "Press: %.0fhPa", pressure);
        lv_label_set_text(pressure_label, press_str);
    }
}