#pragma once
#include <stdio.h>
#include "driver/i2c_master.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Initialize the BME680 sensor
 */
esp_err_t init_handle_bme680(i2c_master_dev_handle_t *dev_handle, i2c_master_bus_handle_t i2c_bus, uint8_t dev_address, uint32_t I2C_FREQ_HZ);

/*
 * Read temperature, humidity, pressure, and gas from the BME680 sensor
 */
esp_err_t bme680_read(float *t_c, float *rh, float *pressure, float *gas, i2c_master_dev_handle_t bme680_dev_handle);

#ifdef __cplusplus
}
#endif