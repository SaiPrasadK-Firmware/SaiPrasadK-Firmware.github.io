#ifndef __LCD_I2C_H
#define __LCD_I2C_H

#include "stm32f4xx_hal.h"

#define LCD_ADDR (0x27 << 1)

void LCD_Init(void);
void LCD_SendCommand(uint8_t cmd);
void LCD_SendData(uint8_t data);
void LCD_SendString(char *str);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Clear(void);

#endif
