#include "MPU9250.h"

MPU9250_Result_t MPU9250_Initialize(MPU9250_CONFIG_t *MPU9250_CONFIG){
    uint8_t cmdbuf[8];
	HAL_StatusTypeDef res;

    /* MPU9250_WHO_AM_I ---------------------------------------------------------*/
    cmdbuf[0] = MPU9250_WHO_AM_I|0x80;

    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //WHO_AM_I Check 
    if (cmdbuf[1] != 0x71) {
    	return MPU9250_RESULT_FAIL;
    }
    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    /* MPU9250_Reset ----------------------------------------------------------*/

    cmdbuf[0] = MPU9250_PWR_MGMT_1;
    cmdbuf[1] = 0x00;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    HAL_Delay(100);

    /* MPU9250_I2C_Bypass_mode_enable ---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_INT_PIN_CFG;
    cmdbuf[1] = 0x12;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    /* MPU9250_I2C_Master_enable ---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_USER_CTRL;
    cmdbuf[1] = 0x30;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    /* MPU9250_Set_I2C_clock_400kbps ---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_I2C_MST_CTRL;
    cmdbuf[1] = 0x0D;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    /* AK8963_Reset ---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_I2C_SLV0_ADDR;
    cmdbuf[1] = AK8963_ADDRESS;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_REG;
    cmdbuf[1] = AK8963_CNTL2;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_DO;
    cmdbuf[1] = 0x01;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_CTRL;
    cmdbuf[1] = 0x81;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,8,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }
    HAL_Delay(100);

    /* AK8963_Set_16bit_continuous_measurement_mode_2 ---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_I2C_SLV0_ADDR;
    cmdbuf[1] = AK8963_ADDRESS;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_REG;
    cmdbuf[1] = AK8963_CNTL1;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_DO;
    cmdbuf[1] = 0x16;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_CTRL;
    cmdbuf[1] = 0x81;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }
    
    HAL_Delay(100);

    /* AK8963_WHO_AM_I ---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_I2C_SLV0_ADDR;
    cmdbuf[1] = AK8963_ADDRESS|0x80;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_REG;
    cmdbuf[1] = AK8963_WIA;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_CTRL;
    cmdbuf[1] = 0x81;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    HAL_Delay(100);

    cmdbuf[0] = MPU9250_EXT_SENS_DATA_00|0x80;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }
    //WHO_AM_I Check 
    if (cmdbuf[1] != 0x48) {
    	return MPU9250_RESULT_FAIL;
    }

    return MPU9250_RESULT_OK;
}

MPU9250_Result_t MPU9250_Config(MPU9250_CONFIG_t *MPU9250_CONFIG){
    uint8_t cmdbuf[4];
    HAL_StatusTypeDef res;

    /* MPU9250_Set_Accel_Scale ---------------------------------------------------------*/
    cmdbuf[0] = MPU9250_CONFIG->ACCEL_SCALE;
    if(cmdbuf[0] == ACCEL_SCALE_2G){//2G
        MPU9250_CONFIG->ARES = 2.0;
    }
    else if(cmdbuf[0] == ACCEL_SCALE_4G){//4G
        MPU9250_CONFIG->ARES = 4.0;
    }
    else if(cmdbuf[0] == ACCEL_SCALE_8G){//8G
        MPU9250_CONFIG->ARES = 8.0;
    }
    else if(cmdbuf[0] == ACCEL_SCALE_16G){//16G
        MPU9250_CONFIG->ARES = 16.0;
    }

    cmdbuf[0] = MPU9250_ACCEL_CONFIG|0x80;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_ACCEL_CONFIG;
    cmdbuf[1] = cmdbuf[1] | MPU9250_CONFIG->ACCEL_SCALE;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    /* MPU9250_GYRO_CONFIG ---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_CONFIG->GYRO_SCALE;
    if(cmdbuf[0] == GYRO_SCALE_250dps){//250dps
        MPU9250_CONFIG->GRES = 250;
    }
    else if(cmdbuf[0] == GYRO_SCALE_500dps){//500dps
        MPU9250_CONFIG->GRES = 500;
    }
    else if(cmdbuf[0] == GYRO_SCALE_1000dps){//1000dps
        MPU9250_CONFIG->GRES = 1000;
    }
    else if(cmdbuf[0] == GYRO_SCALE_2000dps){//2000dps
        MPU9250_CONFIG->GRES = 2000;
    }

    cmdbuf[0] = MPU9250_GYRO_CONFIG|0x80;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_GYRO_CONFIG;
    cmdbuf[1] = cmdbuf[1] | MPU9250_CONFIG->ACCEL_SCALE;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    /* AK8963_Get_MAG_Sensitivity ---------------------------------------------------------*/
    /* AK8963_Set_Fuse_access_mode ---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_I2C_SLV0_ADDR;
    cmdbuf[1] = AK8963_ADDRESS;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);
    cmdbuf[0] = MPU9250_I2C_SLV0_REG;
    cmdbuf[1] = AK8963_CNTL1;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_DO;
    cmdbuf[1] = 0x0F;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_CTRL;
    cmdbuf[1] = 0x81;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    HAL_Delay(500);

    /* AK8963_Get_MAG_Sensitivity ---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_I2C_SLV0_ADDR;
    cmdbuf[1] = AK8963_ADDRESS|0x80;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_REG;
    cmdbuf[1] = AK8963_ASAX;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_CTRL;
    cmdbuf[1] = 0x83;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    HAL_Delay(500);

    cmdbuf[0] = MPU9250_EXT_SENS_DATA_00|0x80;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,4,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    for(int i=0;i<3;i++){
        MPU9250_CONFIG->MAG_SENSITIVITY[i] = (((cmdbuf[i+1] -128)*0.5)/128)+1;
    }

    /* AK8963_Set_16bit_continuous_measurement_mode_2 ---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_I2C_SLV0_ADDR;
    cmdbuf[1] = AK8963_ADDRESS;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_REG;
    cmdbuf[1] = AK8963_CNTL1;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_DO;
    cmdbuf[1] = 0x16;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_CTRL;
    cmdbuf[1] = 0x81;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    HAL_Delay(100);

    //Ex
    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    return MPU9250_RESULT_OK;
}

MPU9250_Result_t MPU9250_Update7DOF(MPU9250_CONFIG_t *MPU9250_CONFIG,MPU9250_DATA_t *MPU9250_DATA){
    uint8_t cmdbuf[15];
    HAL_StatusTypeDef res;

    /* MPU9250_Get_Accel_Gyro_and_Temp ---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_ACCEL_XOUT_H|0x80;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,15,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    for(int i=0;i<3;i++){
        MPU9250_DATA->accel_raw[i] = (uint16_t)cmdbuf[2*i+1] << 8 | cmdbuf[2*i+2];
        MPU9250_DATA->gyro_raw[i] = (uint16_t)cmdbuf[2*i+9] << 8 | cmdbuf[2*i+10];
        MPU9250_DATA->accel[i] = ((int16_t)MPU9250_DATA->accel_raw[i] * MPU9250_CONFIG->ARES)/32768.0 - MPU9250_CONFIG->ACCEL_OFFSET[i];
        MPU9250_DATA->gyro[i] = ((int16_t)MPU9250_DATA->gyro_raw[i] * MPU9250_CONFIG->GRES)/32768.0 - MPU9250_CONFIG->GYRO_OFFSET[i];
    }
    MPU9250_DATA->temperature_raw = ((uint16_t)cmdbuf[7] << 8) | cmdbuf[8];
    MPU9250_DATA->temperature = (MPU9250_DATA->temperature_raw/333.87) + 21.0;

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    return MPU9250_RESULT_OK;
}

MPU9250_Result_t MPU9250_UpdateMAG(MPU9250_CONFIG_t *MPU9250_CONFIG,MPU9250_DATA_t *MPU9250_DATA){
    uint8_t cmdbuf[8];
    HAL_StatusTypeDef res;

    /* MPU9250_Update_MAG (Do not Get)---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_I2C_SLV0_ADDR;
    cmdbuf[1] = AK8963_ADDRESS|0x80;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_REG;
    cmdbuf[1] = AK8963_HXL;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    cmdbuf[0] = MPU9250_I2C_SLV0_CTRL;
    cmdbuf[1] = 0x87;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,2,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    /* MPU9250_Get_MAG ---------------------------------------------------------*/
    /*
    cmdbuf[0] = MPU9250_EXT_SENS_DATA_00|0x80;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,8,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }


    for(int i=0;i<3;i++){
        MPU9250_DATA->mag_raw[i] = (uint16_t)cmdbuf[2*i+2] << 8 | cmdbuf[2*i+1];
        MPU9250_DATA->mag[i] = (0.15 * (int16_t)MPU9250_DATA->mag_raw[i] * MPU9250_CONFIG->MAG_SENSITIVITY[i]) - MPU9250_CONFIG->MAG_OFFSET[i];
    }
    */

    return MPU9250_RESULT_OK;
}

MPU9250_Result_t MPU9250_GetMAG(MPU9250_CONFIG_t *MPU9250_CONFIG,MPU9250_DATA_t *MPU9250_DATA){
    uint8_t cmdbuf[8];
    HAL_StatusTypeDef res;

    /* MPU9250_Get_MAG ---------------------------------------------------------*/

    cmdbuf[0] = MPU9250_EXT_SENS_DATA_00|0x80;
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 0);
    res = HAL_SPI_TransmitReceive(MPU9250_CONFIG->hspi,cmdbuf,cmdbuf,8,0xFFFF);
    HAL_GPIO_WritePin(MPU9250_CONFIG->GPIOx,MPU9250_CONFIG->GPIO_PIN , 1);

    if (res != HAL_OK) {
    	return MPU9250_RESULT_FAIL;
    }

    for(int i=0;i<3;i++){
        MPU9250_DATA->mag_raw[i] = (uint16_t)cmdbuf[2*i+2] << 8 | cmdbuf[2*i+1];
        MPU9250_DATA->mag[i] = (0.15 * (int16_t)MPU9250_DATA->mag_raw[i] * MPU9250_CONFIG->MAG_SENSITIVITY[i]) - MPU9250_CONFIG->MAG_OFFSET[i];
    }

    return MPU9250_RESULT_OK;
}

MPU9250_Result_t MPU9250_Calibrate(MPU9250_CONFIG_t *MPU9250_CONFIG){
    MPU9250_DATA_t MPU9250_TEMP;
    float ax_sum=0,ay_sum=0,az_sum=0;
    float gx_sum=0,gy_sum=0,gz_sum=0;

    /* MPU9250_Accel_Gyro_Calibration---------------------------------------------------------*/

    for(int i=0;i<CALIBRATE_TIMES;i++){//Take samples by the number of CALIBRATE_TIME
        MPU9250_Update7DOF(MPU9250_CONFIG,&MPU9250_TEMP);
        ax_sum += MPU9250_TEMP.accel[0];
        ay_sum += MPU9250_TEMP.accel[1];
        az_sum += MPU9250_TEMP.accel[2] - 1;

        gx_sum += MPU9250_TEMP.gyro[0];
        gy_sum += MPU9250_TEMP.gyro[1];
        gz_sum += MPU9250_TEMP.gyro[2];
    }
    MPU9250_CONFIG->ACCEL_OFFSET[0] = ax_sum/CALIBRATE_TIMES;
    MPU9250_CONFIG->ACCEL_OFFSET[1] = ay_sum/CALIBRATE_TIMES;
    MPU9250_CONFIG->ACCEL_OFFSET[2] = az_sum/CALIBRATE_TIMES;

    MPU9250_CONFIG->GYRO_OFFSET[0] = gx_sum/CALIBRATE_TIMES;
    MPU9250_CONFIG->GYRO_OFFSET[1] = gy_sum/CALIBRATE_TIMES;
    MPU9250_CONFIG->GYRO_OFFSET[2] = gz_sum/CALIBRATE_TIMES;

    return MPU9250_RESULT_OK;
}