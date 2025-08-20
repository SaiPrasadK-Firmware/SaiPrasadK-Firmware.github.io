#include "eeprom_24c04.h"

extern I2C_HandleTypeDef hi2c1;

void EEPROM_Write(uint16_t addr, uint8_t data) {
    uint8_t buf[2] = {addr, data};
    HAL_I2C_Master_Transmit(&hi2c1, EEPROM_ADDR, buf, 2, HAL_MAX_DELAY);
    HAL_Delay(5); // write cycle
}

uint8_t EEPROM_Read(uint16_t addr) {
    uint8_t data;
    uint8_t memAddr = addr & 0xFF;
    HAL_I2C_Master_Transmit(&hi2c1, EEPROM_ADDR, &memAddr, 1, HAL_MAX_DELAY);
    HAL_I2C_Master_Receive(&hi2c1, EEPROM_ADDR, &data, 1, HAL_MAX_DELAY);
    return data;
}
