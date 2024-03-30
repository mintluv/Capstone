/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    spi.h
  * @brief   This file contains all the function prototypes for
  *          the spi.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPI_H__
#define __SPI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_SPI1_Init(void);
typedef struct __NCS_IO
{
    GPIO_TypeDef *port;
    uint16_t pin;
} ncs_io;
uint8_t spi_wr_byte(SPI_HandleTypeDef *hspi, uint8_t byte);

void spi_w_bytes(SPI_HandleTypeDef *hspi, uint8_t address, uint8_t *bytes,
                 uint16_t num, ncs_io cs);

void spi_r_bytes(SPI_HandleTypeDef *hspi, uint8_t address, uint8_t num,
                 ncs_io cs);

void spi_w_byte(SPI_HandleTypeDef *hspi, uint8_t address, uint8_t byte, ncs_io cs);

uint8_t spi_r_byte(SPI_HandleTypeDef *hspi, uint8_t address, ncs_io cs);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __SPI_H__ */

