idf_component_register(
    SRCS "i2c_hal.c" "lvgl_ui.c" "main.c"
    INCLUDE_DIRS "."
    REQUIRES driver sh1107 sht41
)