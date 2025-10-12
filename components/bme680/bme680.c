#include <stdio.h>
#include "bme680.h"

esp_err_t init_handle_bme680(i2c_master_dev_handle_t *dev_handle, i2c_master_bus_handle_t i2c_bus, uint8_t dev_address, uint32_t I2C_FREQ_HZ)
{
    if (dev_handle == NULL || i2c_bus == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    i2c_device_config_t dev_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = dev_address,
        .scl_speed_hz = I2C_FREQ_HZ,
    };

    return i2c_master_bus_add_device(i2c_bus, &dev_cfg, dev_handle);
}

// esp_err_t bme

// esp_err_t bme680_read(float *t_c, float *rh, float *pressure, float *gas, i2c_master_dev_handle_t bme680_dev_handle)
// {
    
// }