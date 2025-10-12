#pragma once
#include <stdio.h>
#include "driver/i2c_master.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Initialize the SHT41 sensor
 */
esp_err_t init_handle_sht41(i2c_master_dev_handle_t *dev_handle, i2c_master_bus_handle_t i2c_bus, uint8_t dev_address, uint32_t I2C_FREQ_HZ);

/*
 * Read temperature and humidity from the SHT41 sensor
 */
esp_err_t sht41_tmp_hmd_read(float *t_c, float *rh, i2c_master_dev_handle_t sht41_dev_handle);

esp_err_t sht41_soft_reset(i2c_master_dev_handle_t sht41_dev_handle);

esp_err_t sht41_serial_number(i2c_master_dev_handle_t sht41_dev_handle, uint32_t *serial_number);

#ifdef __cplusplus
}
#endif
