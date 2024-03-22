/*
 * led.h
 *
 *  Created on: Mar 13, 2024
 *      Author: miste
 */

#ifndef SRC_COMMON_HW_INCLUDE_LED_H_
#define SRC_COMMON_HW_INCLUDE_LED_H_

#include "hw_def.h"   // hw 모듈들은 hw def를 include 해야 함. 여기 hw 관련 정의가 들어있기 때문


#ifdef _USE_HW_LED  // LED를 사용하는 경우에만 사용하는 api들

#define LED_MAX_CH          HW_LED_MAX_CH      // LED 몇 개 사용하는지 hw def.h에서 정의

bool ledInit(void);         // api 만들기
void ledOn(uint8_t ch);     // led 여러 개 사용한다는 가정으로 ch 변수
void ledOff(uint8_t ch);     
void ledToggle(uint8_t ch);     

#endif

#endif /* SRC_COMMON_HW_INCLUDE_LED_H_ */
