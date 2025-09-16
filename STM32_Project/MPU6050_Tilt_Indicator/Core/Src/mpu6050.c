#include "mpu6050.h"

#define ACCEL_XOUT_H 0x3B
#define PWR_MGMT_1   0x6B

HAL_StatusTypeDef MPU6050_Init(I2C_HandleTypeDef *hi2c)
{
    uint8_t check;
    uint8_t data;

    HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, 0x75, 1, &check, 1, 1000);
    if (check == 0x68) {
        data = 0;
        HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, PWR_MGMT_1, 1, &data, 1, 1000);
        return HAL_OK;
    }
    return HAL_ERROR;
}

HAL_StatusTypeDef MPU6050_ReadAccel(I2C_HandleTypeDef *hi2c, MPU6050_Data *data)
{
    uint8_t rec[6];
    if (HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, ACCEL_XOUT_H, 1, rec, 6, 1000) == HAL_OK) {
        data->Accel_X = (int16_t)(rec[0] << 8 | rec[1]);
        data->Accel_Y = (int16_t)(rec[2] << 8 | rec[3]);
        data->Accel_Z = (int16_t)(rec[4] << 8 | rec[5]);
        return HAL_OK;
    }
    return HAL_ERROR;
}
