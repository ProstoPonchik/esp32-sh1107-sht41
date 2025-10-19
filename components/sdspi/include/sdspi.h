#pragma once

#define MOUNT_POINT "/sdcard"

#define SDSPI_CS_PIN            (gpio_num_t)GPIO_NUM_9
#define SDSPI_CLK_PIN           (gpio_num_t)GPIO_NUM_10
#define SDSPI_MOSI_PIN          (gpio_num_t)GPIO_NUM_11
#define SDSPI_MISO_PIN          (gpio_num_t)GPIO_NUM_12

void mount_sd_over_spi();