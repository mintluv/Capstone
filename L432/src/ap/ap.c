/*
 * ap.c
 *
 *  Created on: Mar 23, 2024
 *      Author: Min
 */


#include "ap.h"

void apInit(void){
}

void apMain(void){
  uint32_t pre_time;


  pre_time = millis();
  while(1)
  {
    if (millis()-pre_time >= 100)
    {
      pre_time = millis();
      ledToggle(0);
    }
  }
}


