#ifndef TILT_H
#define TILT_H

#include "stm32f4xx_hal.h"
#include "mpu6050.h"

void Tilt_Check(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef *huart);

#endif
