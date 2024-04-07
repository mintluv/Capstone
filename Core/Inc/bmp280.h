#ifndef __BMP280_BARO
#define __BMP280_BARO

#include "main.h"

// Set port and pin for barometer here
#define BARO_CS_PORT GPIOC
#define BARO_CS_PIN CS_BMP_Pin

typedef struct BaroData {
    int32_t temperature; // temperature in units of 0.01 DegC
    uint32_t pressure; // pressure in units of 
} BaroData;

typedef struct BaroStatus {
    uint8_t isConverting;
    uint8_t isCopying;
} BaroStatus;

#define BARO_OVERSAMP_TEMP_NONE 0b00000000
#define BARO_OVERSAMP_TEMP_01x  0b00100000
#define BARO_OVERSAMP_TEMP_02x  0b01000000
#define BARO_OVERSAMP_TEMP_04x  0b01100000
#define BARO_OVERSAMP_TEMP_08x  0b10000000
#define BARO_OVERSAMP_TEMP_16x  0b10100000

#define BARO_OVERSAMP_PRESS_NONE 0b00000000
#define BARO_OVERSAMP_PRESS_01x  0b00000100
#define BARO_OVERSAMP_PRESS_02x  0b00001000
#define BARO_OVERSAMP_PRESS_04x  0b00001100
#define BARO_OVERSAMP_PRESS_08x  0b00010000
#define BARO_OVERSAMP_PRESS_16x  0b00010100

#define BARO_POWERMODE_SLEEP  0x00
#define BARO_POWERMODE_FORCED 0x01
#define BARO_POWERMODE_NORMAL 0x03

// All units in ms
#define BARO_T_STANDBY_0p5  0b00000000
#define BARO_T_STANDBY_62p5 0b00100000
#define BARO_T_STANDBY_125  0b01000000
#define BARO_T_STANDBY_250  0b01100000
#define BARO_T_STANDBY_500  0b10000000
#define BARO_T_STANDBY_1000 0b10100000
#define BARO_T_STANDBY_2000 0b11000000
#define BARO_T_STANDBY_4000 0b11100000

// IRR filter coefficients
#define BARO_FILTERCOEFF_OFF 0b00000000
#define BARO_FILTERCOEFF_2   0b00000100
#define BARO_FILTERCOEFF_4   0b00001000
#define BARO_FILTERCOEFF_8   0b00001100
#define BARO_FILTERCOEFF_16  0b00010000


int BARO_INIT(SPI_HandleTypeDef* spiHandler);
void BARO_GOOD_SETTINGS();

// Read functions

uint8_t BARO_READ_ID();

BaroData BARO_READ_DATA();

BaroStatus BARO_READ_STATUS();

void RELOAD_CONFIG();
void RELOAD_SAMPLING_OPTIONS();

// Write functions

void SET_SAMPLING_OPTIONS(uint8_t oversampTemp, uint8_t oversampPress, uint8_t powerMode);
void SET_POWERMODE(uint8_t powerMode);

void SET_CONFIG(uint8_t timeStandby, uint8_t filterCoeff);

#endif
