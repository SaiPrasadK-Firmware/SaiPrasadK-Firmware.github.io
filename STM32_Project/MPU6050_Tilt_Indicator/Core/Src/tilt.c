#include "tilt.h"
#include "lcd.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GREEN_LED_PIN GPIO_PIN_5
#define RED_LED_PIN   GPIO_PIN_6
#define LED_PORT      GPIOA

#define THRESHOLD 2000   // adjust based on sensitivity

void Tilt_Check(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef *huart)
{
    MPU6050_Data data;
    char msg[64];

    // Read accelerometer data
    if (MPU6050_ReadAccel(hi2c, &data) != HAL_OK) return;

    // Stable condition (both X and Y within threshold)
    if (abs(data.Accel_X) < THRESHOLD && abs(data.Accel_Y) < THRESHOLD) {
        HAL_GPIO_WritePin(LED_PORT, GREEN_LED_PIN, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LED_PORT, RED_LED_PIN, GPIO_PIN_RESET);

        LCD_Clear();
        LCD_Print("Device Stable");

        sprintf(msg, "Stable | AccelX=%d, AccelY=%d\r\n", data.Accel_X, data.Accel_Y);
        HAL_UART_Transmit(huart, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
    }
    else {
        HAL_GPIO_WritePin(LED_PORT, GREEN_LED_PIN, GPIO_PIN_RESET);
        HAL_GPIO_TogglePin(LED_PORT, RED_LED_PIN);

        LCD_Clear();

        // Check X-axis tilt
        if (data.Accel_X > THRESHOLD) {
            LCD_Print("Device Tilted Right");
            sprintf(msg, "Right Tilt | AccelX=%d\r\n", data.Accel_X);
        }
        else if (data.Accel_X < -THRESHOLD) {
            LCD_Print("Device Tilted Left");
            sprintf(msg, "Left Tilt | AccelX=%d\r\n", data.Accel_X);
        }
        // Check Y-axis tilt
        else if (data.Accel_Y > THRESHOLD) {
            LCD_Print("Device Tilted Forward");
            sprintf(msg, "Forward Tilt | AccelY=%d\r\n", data.Accel_Y);
        }
        else if (data.Accel_Y < -THRESHOLD) {
            LCD_Print("Device Tilted Backward");
            sprintf(msg, "Backward Tilt | AccelY=%d\r\n", data.Accel_Y);
        }
        else {
            // Fallback (in case only one axis is slightly over threshold)
            LCD_Print("Device Tilted");
            sprintf(msg, "Tilted | X=%d Y=%d\r\n", data.Accel_X, data.Accel_Y);
        }

        HAL_UART_Transmit(huart, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
    }
}
