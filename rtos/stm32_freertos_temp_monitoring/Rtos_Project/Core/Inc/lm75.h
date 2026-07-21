/*
 * lm75.h
 *
 *  Created on: Jul 21, 2026
 *      Author: sreerag
 */

#ifndef INC_LM75_H_
#define INC_LM75_H_

#include "main.h"


HAL_StatusTypeDef LM75_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef LM75_ReadTemperature(float *temperature);

#endif /* INC_LM75_H_ */
