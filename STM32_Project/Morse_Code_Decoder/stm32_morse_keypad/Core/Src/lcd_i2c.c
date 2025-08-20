/*
 * lcd_i2c.c
 *
 *  Created on: Aug 18, 2025
 *      Author: Sai
 */


#include "lcd_i2c.h"

extern I2C_HandleTypeDef hi2c1;

#define LCD_BACKLIGHT 0x08
#define LCD_ENABLE    0x04

static void LCD_Write(uint8_t data) {
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, &data, 1, HAL_MAX_DELAY);
}

static void LCD_Send4Bits(uint8_t data) {
    LCD_Write(data | LCD_BACKLIGHT);
    LCD_Write(data | LCD_BACKLIGHT | LCD_ENABLE);
    HAL_Delay(1);
    LCD_Write((data & ~LCD_ENABLE) | LCD_BACKLIGHT);
}

void LCD_SendCommand(uint8_t cmd) {
    LCD_Send4Bits(cmd & 0xF0);
    LCD_Send4Bits((cmd << 4) & 0xF0);
}

void LCD_SendData(uint8_t data) {
    LCD_Send4Bits((data & 0xF0) | 0x01);
    LCD_Send4Bits(((data << 4) & 0xF0) | 0x01);
}

void LCD_Init(void) {
    HAL_Delay(50);
    LCD_SendCommand(0x33);
    LCD_SendCommand(0x32);
    LCD_SendCommand(0x28);
    LCD_SendCommand(0x0C);
    LCD_SendCommand(0x06);
    LCD_SendCommand(0x01);
    HAL_Delay(5);
}

void LCD_SendString(char *str) {
    while (*str) {
        LCD_SendData(*str++);
    }
}

void LCD_SetCursor(uint8_t row, uint8_t col) {
    uint8_t addr = (row == 0) ? 0x80 : 0xC0;
    addr += col;
    LCD_SendCommand(addr);
}

void LCD_Clear(void) {
    LCD_SendCommand(0x01);
    HAL_Delay(2);
}
