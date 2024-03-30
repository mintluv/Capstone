/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    spi.c
  * @brief   This file provides code for the configuration
  *          of the SPI instances.
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
/* Includes ------------------------------------------------------------------*/
#include "spi.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

SPI_HandleTypeDef hspi1;

/* SPI1 init function */
void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_4BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

void HAL_SPI_MspInit(SPI_HandleTypeDef* spiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(spiHandle->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspInit 0 */

  /* USER CODE END SPI1_MspInit 0 */
    /* SPI1 clock enable */
    __HAL_RCC_SPI1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**SPI1 GPIO Configuration
    PA5     ------> SPI1_SCK
    PA7     ------> SPI1_MOSI
    PB4 (NJTRST)     ------> SPI1_MISO
    */
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN SPI1_MspInit 1 */

  /* USER CODE END SPI1_MspInit 1 */
  }
}

void HAL_SPI_MspDeInit(SPI_HandleTypeDef* spiHandle)
{

  if(spiHandle->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspDeInit 0 */

  /* USER CODE END SPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI1_CLK_DISABLE();

    /**SPI1 GPIO Configuration
    PA5     ------> SPI1_SCK
    PA7     ------> SPI1_MOSI
    PB4 (NJTRST)     ------> SPI1_MISO
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_5|GPIO_PIN_7);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_4);

  /* USER CODE BEGIN SPI1_MspDeInit 1 */

  /* USER CODE END SPI1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
__attribute((aligned(8))) uint8_t spiDataBuf[16] = {0}; // all read data will store in this array
static uint16_t i = 0;                                                // loop control

/*** basic spi operate ***/
/*** I want to make these functions can be reused ***/
/*
 * @brief   write a byte through SPI and read feedback
 * @param   byte: byte to write
 * @return  received byte
 * */
uint8_t spi_wr_byte(SPI_HandleTypeDef *hspi, uint8_t byte)
{
    uint8_t feedback = 0;

    // wait SPI serial free
    while (HAL_SPI_GetState(hspi) == HAL_SPI_STATE_BUSY_TX_RX)
        ;

    if (HAL_SPI_TransmitReceive(hspi, &byte, &feedback, 1, 0x0100) != HAL_OK)
    {
        return 0xff;
    }

    return feedback;
}
/*
 * @brief   write several bytes through SPI
 * @param   address: address of the first reg
 * @param   bytes: bytes to write
 * @param   num: number of bytes
 * */
void spi_w_bytes(SPI_HandleTypeDef *hspi, uint8_t address, uint8_t *bytes,
                 uint16_t num, ncs_io cs)
{

    HAL_GPIO_WritePin(cs.port, cs.pin, GPIO_PIN_RESET);

    spi_wr_byte(hspi, address);
    for (i = 0; i < num; i++)
        spi_wr_byte(hspi, bytes[i]);

    HAL_GPIO_WritePin(cs.port, cs.pin, GPIO_PIN_SET);
}

/*
 * @brief   read several bytes through SPI
 *          to get the data, check spiDataBuf[0...num-1]
 * @param   address: address of the first reg
 * @param   num: number of bytes to read, number < DATABUF_SIZ
 * @return  data read array
 * */
void spi_r_bytes(SPI_HandleTypeDef *hspi, uint8_t address, uint8_t num,
                 ncs_io cs)
{
    uint8_t _address = address | 0x80;

    HAL_GPIO_WritePin(cs.port, cs.pin, GPIO_PIN_RESET);

    // may be can use HAL_SPI_TransmitReceive()
    HAL_SPI_Transmit(hspi, &_address, 1, 0x0100);
    HAL_SPI_Receive(hspi, spiDataBuf, num, 0x0100); // store read data to spiDataBuf

    HAL_GPIO_WritePin(cs.port, cs.pin, GPIO_PIN_SET);
}

/*
 * @brief   read a byte through SPI
 * @param   address: address of the first reg
 * */
void spi_w_byte(SPI_HandleTypeDef *hspi, uint8_t address, uint8_t byte,
                ncs_io cs)
{

    HAL_GPIO_WritePin(cs.port, cs.pin, GPIO_PIN_RESET);

    spi_wr_byte(hspi, address);
    spi_wr_byte(hspi, byte);

    HAL_GPIO_WritePin(cs.port, cs.pin, GPIO_PIN_SET);
}

/*
 * @brief   read a byte through SPI
 * @param   address: address of the first reg
 * @return  data read out
 * */
uint8_t spi_r_byte(SPI_HandleTypeDef *hspi, uint8_t address, ncs_io cs)
{
    uint8_t _address = address | 0x80;
    HAL_GPIO_WritePin(cs.port, cs.pin, GPIO_PIN_RESET);

    HAL_SPI_Transmit(hspi, &_address, 1, 0x0100);
    HAL_SPI_Receive(hspi, spiDataBuf, 1, 0x0100); // store read data to spiDataBuf

    HAL_GPIO_WritePin(cs.port, cs.pin, GPIO_PIN_SET);
    return spiDataBuf[0];
}
/* USER CODE END 1 */
