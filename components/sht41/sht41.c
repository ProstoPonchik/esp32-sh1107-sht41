#include <stdio.h>
#include "sht41.h"
#include "esp_log.h"
#include "esp_check.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


static const char *TAG = "sht41";

// CRC-8 для Sensirion (polynomial 0x31, init 0xFF)
static uint8_t sensirion_crc8(const uint8_t *data, int len) {
    uint8_t crc = 0xFF;
    for (int i = 0; i < len; i++) {
        crc ^= data[i];
        for (int b = 0; b < 8; b++) {
            if (crc & 0x80) crc = (crc << 1) ^ 0x31;
            else            crc <<= 1;
        }
    }
    return crc;
}

esp_err_t init_handle_sht41(i2c_master_dev_handle_t *dev_handle, i2c_master_bus_handle_t i2c_bus, uint8_t dev_address, uint32_t I2C_FREQ_HZ) {
    if (!dev_handle || !i2c_bus) {
        return ESP_ERR_INVALID_ARG;
    }
    i2c_device_config_t dev_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = dev_address,
        .scl_speed_hz = I2C_FREQ_HZ,
    };
    return i2c_master_bus_add_device(i2c_bus, &dev_cfg, dev_handle);
}

esp_err_t sht41_serial_number(i2c_master_dev_handle_t sht41_dev_handle, uint32_t *serial_number)
{
    uint8_t cmd = 0x89; // Command for reading serial number from datasheet
    ESP_RETURN_ON_ERROR(i2c_master_transmit(sht41_dev_handle, &cmd, sizeof(cmd), pdMS_TO_TICKS(portMAX_DELAY)), TAG, "tx cmd read serial number failed");

    vTaskDelay(pdMS_TO_TICKS(10));

    uint8_t rx[6] = {0};
    ESP_RETURN_ON_ERROR(i2c_master_receive(sht41_dev_handle, rx, sizeof(rx), pdMS_TO_TICKS(portMAX_DELAY)), TAG, "rx read serial number");

    if (sensirion_crc8(rx, 2) != rx[2] || sensirion_crc8(rx + 3, 2) != rx[5]) {
        return ESP_ERR_INVALID_CRC;
    }

    uint16_t hi = ((uint16_t)rx[0] << 8) | rx[1];
    uint16_t lo = ((uint16_t)rx[3] << 8) | rx[4];

    if (serial_number) {
        *serial_number = ((uint32_t)hi << 16) | lo;
    }
    return ESP_OK;
}

esp_err_t sht41_soft_reset(i2c_master_dev_handle_t sht41_dev_handle) {
    uint8_t cmd = 0x94; // Command for soft reset from datasheet
    ESP_RETURN_ON_ERROR(i2c_master_transmit(sht41_dev_handle, &cmd, sizeof(cmd), pdMS_TO_TICKS(portMAX_DELAY)), TAG, "tx cmd soft reset failed");
    return ESP_OK;
}

// Читання температури/вологості (висока точність), повертає t_C
esp_err_t sht41_tmp_hmd_read(float *t_c, float *rh, i2c_master_dev_handle_t sht41_dev_handle) {
    // Команда вимірювання з високою точністю без нагрівача: 0xFD
    uint8_t cmd = 0xFD;
    ESP_RETURN_ON_ERROR(i2c_master_transmit(sht41_dev_handle, &cmd, sizeof(cmd), pdMS_TO_TICKS(portMAX_DELAY)), TAG, "tx cmd start measurement failed");

    // Час вимірювання ~10–15 мс; дамо запас
    vTaskDelay(pdMS_TO_TICKS(20));

    uint8_t rx[6] = {0};
    ESP_RETURN_ON_ERROR(i2c_master_receive(sht41_dev_handle, rx, sizeof(rx), pdMS_TO_TICKS(portMAX_DELAY)), TAG, "rx read measurement failed");

    // Перевірка CRC для T та RH
    if (sensirion_crc8(rx, 2) != rx[2] || sensirion_crc8(rx + 3, 2) != rx[5]) {
        return ESP_ERR_INVALID_CRC;
    }

    uint16_t t_raw  = ((uint16_t)rx[0] << 8) | rx[1];
    uint16_t rh_raw = ((uint16_t)rx[3] << 8) | rx[4];

    // Формули з даташиту
    if (t_c)  *t_c  = -45.0f + 175.0f * ((float)t_raw  / 65535.0f);
    if (rh)   *rh   = -6.0f  + 125.0f * ((float)rh_raw / 65535.0f);

    return ESP_OK;
}