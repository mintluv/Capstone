/*
 * uart.c
 *
 *  Created on: Mar 25, 2024
 *      Author: Min
 */


#include "uart.h"

static bool is_open[UART_MAX_CH];





bool uartInit(void){
    for (int i = 0; i < UART_MAX_CH; i++){
        is_open[i] =false;
    }
}
bool uartOpen(uint8_t ch, uint32_t baud){
    bool ret =false;
    switch (ch)
    {
    case _DEF_UART1:
        is_open[ch] =true;
        ret =true;
        break;
    }

}
uint32_t uartAvaliable(uint8_t ch){
    uint32_t ret =0;
    switch (ch)
    {
    case _DEF_UART1:
        ret = cdcAvail;
        break;
    }
}
uint8_t uartRead(uint8_t ch, uint8_t *p_data,uint32_t length){

}
uint32_t uartWrite(uint32_t ch, uint8_t *p_data, uint32_t length){

}
uint32_t uartPrintf(uint8_t ch, char *fmt, ...){

}
