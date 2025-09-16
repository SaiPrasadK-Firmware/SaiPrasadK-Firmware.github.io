#include "lcd.h"
#include "string.h"

extern I2C_HandleTypeDef hi2c1;
#define LCD_ADDR 0x4E

static void LCD_Send(uint8_t data, uint8_t rs);
static void LCD_SendNibble(uint8_t nibble, uint8_t rs);

void LCD_Init(void)
{
    HAL_Delay(50);
    LCD_SendNibble(0x03, 0);
    HAL_Delay(5);
    LCD_SendNibble(0x03, 0);
    HAL_Delay(5);
    LCD_SendNibble(0x02, 0);

    LCD_Send(0x28, 0);
    LCD_Send(0x0C, 0);
    LCD_Send(0x06, 0);
    LCD_Clear();
}

void LCD_Clear(void) { LCD_Send(0x01, 0); HAL_Delay(2); }

void LCD_SetCursor(uint8_t row, uint8_t col)
{
    uint8_t pos[] = {0x80, 0xC0};
    LCD_Send(pos[row] + col, 0);
}

void LCD_Print(char *str)
{
    uint8_t col = 0;
    uint8_t row = 0;

    while (*str)
    {
        LCD_Send(*str++, 1);
        col++;

        if (col >= 14) {
            // If first line → go to second line normally
            if (row == 0) {
                row = 1;
                col = 0;
                LCD_SetCursor(row, col);
            }
            // If already on second line
            else {
                // Leave 3 spaces before continuing
                LCD_Print("   ");
                col += 3;
                if (col >= 14) {
                    // move cursor to start again if still exceeding
                    LCD_SetCursor(1, 0);
                    col = 0;
                }
            }
        }
    }
}


/* ---- Internal functions ---- */
static void LCD_Send(uint8_t data, uint8_t rs)
{
    LCD_SendNibble(data >> 4, rs);
    LCD_SendNibble(data & 0x0F, rs);
}

static void LCD_SendNibble(uint8_t nibble, uint8_t rs)
{
    uint8_t data = (nibble << 4) | (rs ? 0x01 : 0x00) | 0x08; // backlight ON
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, &data, 1, 10);
    data |= 0x04; HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, &data, 1, 10);
    data &= ~0x04; HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, &data, 1, 10);
}
