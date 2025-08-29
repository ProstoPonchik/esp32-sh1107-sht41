#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Update temperature display on OLED
 * @param temperature Temperature value in Celsius
 */
void update_temperature_display(float temperature);

/**
 * @brief Update humidity display on OLED  
 * @param humidity Humidity value in percentage
 */
void update_humidity_display(float humidity);

/**
 * @brief Update pressure display on OLED
 * @param pressure Pressure value in hPa
 */
void update_pressure_display(float pressure);

#ifdef __cplusplus
}
#endif
