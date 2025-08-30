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
static lv_obj_t *emoji_canvas = NULL;
/* Aligned, palette-capable draw buffer for a 32x32, 1bpp canvas */
LV_DRAW_BUF_DEFINE_STATIC(smiley_buf, 32, 32, LV_COLOR_FORMAT_I1);

/* Draw a simple monochrome smiley on a small canvas (works on 1-bit SH1107) */
static void draw_smiley_on_canvas(lv_obj_t *parent, int x, int y)
{
    const int W = 32;
    const int H = 32;

    emoji_canvas = lv_canvas_create(parent);
    lv_obj_set_pos(emoji_canvas, x, y);
    lv_obj_set_size(emoji_canvas, W, H);
    /* Initialize and attach aligned draw buffer */
    LV_DRAW_BUF_INIT_STATIC(smiley_buf);
    lv_canvas_set_draw_buf(emoji_canvas, &smiley_buf);

    /* Set palette for 1-bit: index0=BLACK, index1=WHITE */
    lv_canvas_set_palette(emoji_canvas, 0, lv_color32_make(0, 0, 0, 255));
    lv_canvas_set_palette(emoji_canvas, 1, lv_color32_make(255, 255, 255, 255));

    /* Fill background (choose white to contrast with inverted panels) */
    lv_canvas_fill_bg(emoji_canvas, lv_color_white(), LV_OPA_COVER);

    /* Initialize a draw layer to use lv_draw_* APIs */
    lv_layer_t layer;
    lv_canvas_init_layer(emoji_canvas, &layer);

    /* Face: filled circle via a full rect with radius=half size */
    lv_draw_rect_dsc_t face_dsc;
    lv_draw_rect_dsc_init(&face_dsc);
    face_dsc.bg_color = lv_color_black();
    face_dsc.bg_opa = LV_OPA_COVER;
    face_dsc.radius = W / 2; /* makes it a circle */
    face_dsc.outline_opa = LV_OPA_TRANSP;
    lv_area_t face_area = { .x1 = 0, .y1 = 0, .x2 = W - 1, .y2 = H - 1 };
    lv_draw_rect(&layer, &face_dsc, &face_area);

    /* Eyes: small white squares (negative space) */
    lv_draw_rect_dsc_t eye_dsc;
    lv_draw_rect_dsc_init(&eye_dsc);
    eye_dsc.bg_color = lv_color_white();
    eye_dsc.bg_opa = LV_OPA_COVER;

    /* Positions tuned for a friendly look */
    lv_area_t eye_left = { .x1 = 9, .y1 = 10, .x2 = 12, .y2 = 13 };
    lv_area_t eye_right = { .x1 = 19, .y1 = 10, .x2 = 22, .y2 = 13 };
    lv_draw_rect(&layer, &eye_dsc, &eye_left);
    lv_draw_rect(&layer, &eye_dsc, &eye_right);

    /* Mouth: a white arc to carve a smile */
    lv_draw_arc_dsc_t mouth_dsc;
    lv_draw_arc_dsc_init(&mouth_dsc);
    mouth_dsc.color = lv_color_white();
    mouth_dsc.opa = LV_OPA_COVER;
    mouth_dsc.width = 3; /* thickness */
    mouth_dsc.center.x = W / 2;
    mouth_dsc.center.y = (H / 2) + 4;
    mouth_dsc.radius = 11;
    mouth_dsc.start_angle = 30;
    mouth_dsc.end_angle = 150;
    lv_draw_arc(&layer, &mouth_dsc);

    /* Finalize drawing */
    lv_canvas_finish_layer(emoji_canvas, &layer);
}

void example_lvgl_demo_ui(lv_disp_t *disp)
{
    lv_obj_t *scr = lv_disp_get_scr_act(disp);
    
    /* Remove all padding and margins from screen */
    lv_obj_set_style_pad_all(scr, 0, LV_PART_MAIN);
    lv_obj_set_style_margin_all(scr, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(scr, 0, LV_PART_MAIN);
    
    /* Centered container for Sensor/Temp/Hum */
    lv_obj_t *panel = lv_obj_create(scr);
    lv_obj_set_size(panel, 128, LV_SIZE_CONTENT);
    lv_obj_set_style_border_width(panel, 0, 0);
    lv_obj_set_style_bg_opa(panel, LV_OPA_TRANSP, 0);
    lv_obj_set_style_pad_all(panel, 0, 0);
    lv_obj_set_flex_flow(panel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_row(panel, 6, 0);
    lv_obj_center(panel);

    /* Sensor label */
    lv_obj_t *sensor_label = lv_label_create(panel);
    lv_label_set_text(sensor_label, "Sensor: SHT41");
    lv_obj_set_width(sensor_label, 128);
    lv_obj_set_style_text_align(sensor_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_font(sensor_label, &lv_font_jb_14, 0);
    
    /* Temperature label */
    temp_label = lv_label_create(panel);
    lv_label_set_text(temp_label, "Temp: --.-°C");
    lv_obj_set_width(temp_label, 128);
    lv_obj_set_style_text_align(temp_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_font(temp_label, &lv_font_jb_14, 0);
    
    /* Humidity label */
    humidity_label = lv_label_create(panel);
    lv_label_set_text(humidity_label, "Hum: --.-%");
    lv_obj_set_width(humidity_label, 128);
    lv_obj_set_style_text_align(humidity_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_font(humidity_label, &lv_font_jb_14, 0);

    
    /* Remove padding from labels */
    lv_obj_set_style_pad_all(temp_label, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(humidity_label, 0, LV_PART_MAIN);
    // lv_obj_set_style_pad_all(pressure_label, 0, LV_PART_MAIN);
    
    /* Add a 32x32 smiley in the top-right corner */
    draw_smiley_on_canvas(scr, 96, 0);

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