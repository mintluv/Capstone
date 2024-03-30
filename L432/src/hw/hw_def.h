/*
 * hw_def.h
 *
 *  Created on: Mar 23, 2024
 *      Author: Min
 */

#ifndef SRC_HW_HW_DEF_H_
#define SRC_HW_HW_DEF_H_


#include "def.h"
#include "bsp.h"




#define _USE_HW_SPI




#define _USE_HW_LED
<<<<<<< HEAD
#define      HW_LED_MAX_CH     2
=======
#define _USE_HW_UART
>>>>>>> main

#define _USE_HW_UART
#define      HW_UART_MAX_CH    4

#define VCP_TX_Pin GPIO_PIN_2
#define VCP_TX_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define VCP_RX_Pin GPIO_PIN_15
#define VCP_RX_GPIO_Port GPIOA

#endif /* SRC_HW_HW_DEF_H_ */
