#ifndef MPU6050_H
#define MPU6050_H

#include "stm32f4xx_hal.h"

#define MPU6050_ADDR 0xD0 // 0x68<<1

typedef struct {
    int16_t Accel_X;
    int16_t Accel_Y;
    int16_t Accel_Z;
} MPU6050_Data;

HAL_StatusTypeDef MPU6050_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef MPU6050_ReadAccel(I2C_HandleTypeDef *hi2c, MPU6050_Data *data);

#endif
