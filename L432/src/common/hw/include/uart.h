/*
 * uart.h
 *
 *  Created on: Mar 25, 2024
 *      Author: Min
 */

#ifndef SRC_COMMON_HW_INCLUDE_UART_H_
#define SRC_COMMON_HW_INCLUDE_UART_H_

#include "hw_def.h"

#ifdef _USE_HW_UART

#define UART_MAX_CH     HW_UART_MAX_CH

bool uartInit(void);
bool uartOpen(uint8_t ch, uint32_t baud);
uint32_t uartAvaliable(uint8_t ch);
uint8_t uartRead(uint8_t ch, uint8_t *p_data,uint32_t length);
uint32_t uartWrite(uint32_t ch, uint8_t *p_data, uint32_t length);
uint32_t uartPrintf(uint8_t ch, char *fmt, ...);

#endif

#endif /* SRC_COMMON_HW_INCLUDE_UART_H_ */
