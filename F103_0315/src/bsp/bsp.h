/*
 * bsp.h
 *
 *  Created on: Mar 13, 2024
 *      Author: miste
 */

#ifndef SRC_BSP_BSP_H_
#define SRC_BSP_BSP_H_

#include "def.h"

#include "stm32f1xx_hal.h"


void bspInit(void);

void delay(uint32_t ms);
uint32_t millis(void);      // 기본적인 함수들 여기다가


void Error_Handler(void);



#endif /* SRC_BSP_BSP_H_ */
