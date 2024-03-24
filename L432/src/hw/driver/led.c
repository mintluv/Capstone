/*
 * led.c
 *
 *  Created on: Mar 24, 2024
 *      Author: Min
 */


#include "led.h"
#include <stm32l432xx.h>




typedef struct{
  GPIO_TypeDef* *port;
  uint16_t Pin;
  GPIO_PinState On_State;
  GPIO_PinState Off_State;
} led_tbl_t;

led_tbl_t led_tb1[LED_MAX_CH] = {
  {GPIOB,GPIO_PIN_0, GPIO_PIN_RESET,GPIO_PIN_SET},
  {GPIOB,GPIO_PIN_1, GPIO_PIN_RESET,GPIO_PIN_SET},
};



bool ledInit(void){
  bool ret = true;
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

    /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);

    /*Configure GPIO pins : PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /*Configure GPIO pin : PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pins : PB0 PB1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  return ret;
}

void ledOn(uint8_t ch){
  if(ch >= LED_MAX_CH) return;
  HAL_GPIO_WritePin(led_tb1[ch].port, led_tb1[ch].Pin, led_tb1[ch].On_State);
}

void ledOff(uint8_t ch){
  if(ch >= LED_MAX_CH) return;
  HAL_GPIO_WritePin(led_tb1[ch].port, led_tb1[ch].Pin, led_tb1[ch].Off_State);
}

void ledToggle(uint8_t ch){
  if(ch >= LED_MAX_CH) return;
  HAL_GPIO_TogglePin(led_tb1[ch].port, led_tb1[ch].Pin);
}
