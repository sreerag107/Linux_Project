/*
 * lm75.c
 *
 *  Created on: Jul 21, 2026
 *      Author: sreerag
 */

#include "lm75.h"

#define LM75_ADDR     (0x48<<1)
#define LM75_TEMP      0x00


static I2C_HandleTypeDef *lm75_i2c = NULL;
extern I2C_HandleTypeDef hi2c1;


HAL_StatusTypeDef LM75_Init(I2C_HandleTypeDef *hi2c)
{
	HAL_StatusTypeDef status;
    lm75_i2c = hi2c;

    status= HAL_I2C_IsDeviceReady(lm75_i2c,LM75_ADDR,3,HAL_MAX_DELAY);

    return status;
}


HAL_StatusTypeDef LM75_ReadTemperature(float *temperature){
	uint8_t value[2];
	int16_t data;

	if(HAL_I2C_Mem_Read(lm75_i2c, LM75_ADDR, LM75_TEMP, I2C_MEMADD_SIZE_8BIT, value, 2, HAL_MAX_DELAY)!=HAL_OK){

		return HAL_ERROR;
	}
	data=((value[0]<<8)|value[1]);
	*temperature=(data>>5)*0.125;


	return HAL_OK;


}



