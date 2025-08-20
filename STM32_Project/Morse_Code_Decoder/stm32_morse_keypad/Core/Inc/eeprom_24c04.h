

#ifndef __EEPROM_24C04_H
#define __EEPROM_24C04_H

#include "stm32f4xx_hal.h"

#define EEPROM_ADDR (0x50 << 1)

void EEPROM_Write(uint16_t addr, uint8_t data);
uint8_t EEPROM_Read(uint16_t addr);

#endif
