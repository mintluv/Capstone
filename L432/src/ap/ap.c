/*
 * ap.c
 *
 *  Created on: Mar 23, 2024
 *      Author: Min
 */

#include "ap.h"

void apInit(void)
{
}

void apMain(void)
{
  SPI_HandleTypeDef hspi1;
  MPU9250_t mpu9250;

  uint32_t pre_time;

  MPU_begin(&hspi1, &mpu9250);

  MPU_readRawData(&hspi1, &mpu9250);

  pre_time = millis();
  while (1)
  {
    if (millis() - pre_time >= 100)
    {
      pre_time = millis();
      ledToggle(0);
    }
  }
}
