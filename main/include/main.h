#pragma once
#include "driver/gpio.h"

#define I2C_PORT             I2C_NUM_0
#define I2C_CLK_HZ           (400 * 1000)  // 400 kHz

#define SHT41_I2C_ADDR       0x44   // from datasheet

#define BME680_I2C_ADDR      0x76   // from datasheet

#define I2C_SDA_PIN_0        (gpio_num_t)GPIO_NUM_17
#define I2C_SCL_PIN_0        (gpio_num_t)GPIO_NUM_18
#define SH1107_RST_PIN        -1 // GPIO for hardware reset of SH1107 display (-1 if not used)
#define SH1107_I2C_ADDR       ESP_LCD_IO_I2C_SH1107_ADDRESS // from datasheet

#define I2C_SDA_PIN_1    (gpio_num_t)GPIO_NUM_5
#define I2C_SCL_PIN_1    (gpio_num_t)GPIO_NUM_6
#define SH1106_RST_PIN        -1 // GPIO for hardware reset of SH1106 display (-1 if not used)
#define SH1106_I2C_ADDR       ESP_LCD_IO_I2C_SH1106_ADDRESS   // from datasheet

#define SH1107_LCD_H_RES              128
#define SH1107_LCD_V_RES              128
// Bit number used to represent command and parameter
#define SH1107_LCD_CMD_BITS           8
#define SH1107_LCD_PARAM_BITS         8

#define SH1106_LCD_H_RES              128
#define SH1106_LCD_V_RES              64

#define SH1106_LCD_CMD_BITS           8
#define SH1106_LCD_PARAM_BITS         8

#define LED_PIN_1               (gpio_num_t)GPIO_NUM_1
#define LED_PIN_2               (gpio_num_t)GPIO_NUM_2
#define LED_PIN_3               (gpio_num_t)GPIO_NUM_38
#define LED_PIN_4               (gpio_num_t)GPIO_NUM_37
#define LED_PIN_5               (gpio_num_t)GPIO_NUM_36

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
