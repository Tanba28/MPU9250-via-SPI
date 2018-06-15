#ifndef __MPU9250_H__
#define __MPU9250_H__

#include "stm32f3xx_hal.h"

//to do resister map
#define AK8963_ADDRESS 0x0C//AK8963slave add
#define MPU9250_WHO_AM_I 0x75//
#define MPU9250_PWR_MGMT_1 0x6B//
#define MPU9250_ACCEL_CONFIG 0x1C//
#define MPU9250_GYRO_CONFIG 0x1B//

#define MPU9250_ACCEL_XOUT_H 0x3B//ACCEL_XOUT_H
#define MPU9250_GYRO_XOUT_H 0x43//GYRO_XOUT_H

#define MPU9250_USER_CTRL 0x6A
#define MPU9250_I2C_MST_CTRL 0x24
#define MPU9250_I2C_MST_DELAY_CTRL 0x67

#define MPU9250_I2C_SLV0_ADDR 0x25
#define MPU9250_I2C_SLV0_REG 0x26
#define MPU9250_I2C_SLV0_CTRL 0x27
#define MPU9250_I2C_SLV0_DO 0x63

#define MPU9250_INT_PIN_CFG 0x37

#define MPU9250_EXT_SENS_DATA_00 0x49



#define AK8963_WIA 0x00
#define AK8963_INFO 0x01
#define AK8963_ST_1 0x02
#define AK8963_HXL 0x03//HXL
#define AK8963_HXH 0x04
#define AK8963_HYL 0x05
#define AK8963_HYX 0x06
#define AK8963_HZL 0x07
#define AK8963_HZH 0x08
#define AK8963_ST2 0x09//ST2
#define AK8963_CNTL1 0x0A//CNTL1
#define AK8963_CNTL2 0x0B
#define AK8963_ASTC 0x0C
#define AK8963_TS1 0x0D
#define AK8963_TS2 0x0E
#define AK8963_I2CDIS 0x0F
#define AK8963_ASAX 0x10//ASAX
#define AK8963_ASAY 0x11//ASAY
#define AK8963_ASAZ 0x12//ASAZ

#define CALIBRATE_TIMES 1000

/* Structure and Valiable ---------------------------------------------------------*/

typedef enum {
	MPU9250_RESULT_OK = 0x00,
	MPU9250_RESULT_FAIL
} MPU9250_Result_t;

typedef enum {
    ACCEL_SCALE_2G  = 0x00,
    ACCEL_SCALE_4G  = 0x08,
    ACCEL_SCALE_8G  = 0x10,
    ACCEL_SCALE_16G = 0x18  
} MPU9250_ACCEL_SCALE_t;

typedef enum {
    GYRO_SCALE_250dps  = 0x00,
    GYRO_SCALE_500dps  = 0x08,
    GYRO_SCALE_1000dps = 0x10,
    GYRO_SCALE_2000dps = 0x18
} MPU9250_GYRO_SCALE_t;

typedef struct {
    SPI_HandleTypeDef *hspi;//SPI handle
    GPIO_TypeDef *GPIOx;//CS pin GPIOx
    uint16_t GPIO_PIN ;//CS pin number

    MPU9250_GYRO_SCALE_t ACCEL_SCALE;
    MPU9250_GYRO_SCALE_t GYRO_SCALE;

    float ARES;//Accel resolution
    float GRES;//Gyro resolution
    float MAG_SENSITIVITY[3];

    float ACCEL_OFFSET[3];
    float GYRO_OFFSET[3];
    float MAG_OFFSET[3];
} MPU9250_CONFIG_t;

typedef struct {
    float accel[3];
    uint16_t accel_raw[3];
    float gyro[3];
    uint16_t gyro_raw[3];
    float mag[3];
    uint16_t mag_raw[3];
    float temperature;
    uint16_t temperature_raw;
} MPU9250_DATA_t;

/* Fanction ---------------------------------------------------------*/

MPU9250_Result_t MPU9250_Initialize(MPU9250_CONFIG_t *MPU9250_CONFIG);
MPU9250_Result_t MPU9250_Config(MPU9250_CONFIG_t *MPU9250_CONFIG);
MPU9250_Result_t MPU9250_MAG_Selftest(MPU9250_CONFIG_t *MPU9250_CONFIG,MPU9250_DATA_t *MPU9250_DATA);
MPU9250_Result_t MPU9250_Update7DOF(MPU9250_CONFIG_t *MPU9250_CONFIG,MPU9250_DATA_t *MPU9250_DATA);
MPU9250_Result_t MPU9250_UpdateMAG(MPU9250_CONFIG_t *MPU9250_CONFIG,MPU9250_DATA_t *MPU9250_DATA);
MPU9250_Result_t MPU9250_GetMAG(MPU9250_CONFIG_t *MPU9250_CONFIG,MPU9250_DATA_t *MPU9250_DATA);
MPU9250_Result_t MPU9250_Calibrate(MPU9250_CONFIG_t *MPU9250_CONFIG);

#endif