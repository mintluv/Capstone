/*
 * bsp.h
 *
 *  Created on: Mar 23, 2024
 *      Author: Min
 */

#ifndef SRC_BSP_BSP_H_
#define SRC_BSP_BSP_H_

#include "def.h"

#include "stm32l4xx_hal.h"



void SystemClock_Config(void);

void bspInit(void);

void delay(uint32_t ms);

uint32_t millis(void);

void Error_Handler(void);


#endif /* SRC_BSP_BSP_H_ */
