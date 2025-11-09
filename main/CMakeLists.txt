idf_component_register(
    SRCS "lvgl_ui.c" "main.c" "lv_font_jb_14.c"
    INCLUDE_DIRS "."
    REQUIRES driver sh1107 sht41 lcd_sh1106 bme680 sdspi
)