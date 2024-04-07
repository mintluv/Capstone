#include "bmp280.h"

// GPIO connectivity
#define PORT BARO_CS_PORT
#define PIN BARO_CS_PIN

#define HIGH GPIO_PIN_SET
#define LOW GPIO_PIN_RESET

// Address Space
#define ADDR_TEMP_XLSB 0xFC
#define ADDR_TEMP_LSB  0xFB
#define ADDR_TEMP_MSB  0xFA
#define ADDR_PRESS_XLSB 0xF9
#define ADDR_PRESS_LSB  0xF8
#define ADDR_PRESS_MSB  0xF7
#define ADDR_CONFIG 0xF5
#define ADDR_CTRL_MEAS 0xF4
#define ADDR_STATUS 0xF3
#define ADDR_RESET 0xE0
#define ADDR_CHIP_ID 0xD0
#define ADDR_CALIB_START 0x88

// trimming parameters
static struct
{
    uint16_t T1;
    int16_t T2;
    int16_t T3;
    uint16_t P1;
    int16_t P2;
    int16_t P3;
    int16_t P4;
    int16_t P5;
    int16_t P6;
    int16_t P7;
    int16_t P8;
    int16_t P9;
} calibData;

// Settings
static uint8_t m_mode;
static uint8_t m_pressOSR;
static uint8_t m_tempOSR;
static uint8_t m_tStandby;
static uint8_t m_filterCoeff;


// Other logic
#define READ 0x80
#define WRITE 0x7F

static SPI_HandleTypeDef* b_hspi;

static void select();
static void unselect();
static void readAddr(uint8_t, uint8_t*, int);
static void writeAddr(uint8_t, uint8_t);
static void loadCalibrationData();

int BARO_INIT(SPI_HandleTypeDef* spiHandler){
    b_hspi = spiHandler;
    if (BARO_READ_ID() ==0x58){
        RELOAD_CONFIG();
        RELOAD_SAMPLING_OPTIONS();
        loadCalibrationData();
        SET_SAMPLING_OPTIONS(BARO_OVERSAMP_TEMP_02x, BARO_OVERSAMP_PRESS_08x, BARO_POWERMODE_NORMAL);
        return 1;
    }
    else{
        return 0;
    }
}
void BARO_GOOD_SETTINGS();

// Read functions

uint8_t BARO_READ_ID(){
    uint8_t id;
    select();
    readAddr(ADDR_CHIP_ID, &id, 1);
    unselect();
    return id;
}

BaroData BARO_READ_DATA(){
    uint8_t rawVals[6];
    int32_t rawTemp;
    int32_t rawPress;
    int32_t tFine;
    BaroData out;
    int32_t var1t, var2t;
    int64_t var1p, var2p, p;

    select();
    readAddr(ADDR_PRESS_MSB, rawVals, 6);
    unselect();

    rawPress = (rawVals[2]>>4) | (rawVals[1]<<4) | (rawVals[0]<<12);
    rawTemp  = (rawVals[5]>>4) | (rawVals[4]<<4) | (rawVals[3]<<12);
    
    // Not gonna lie I have no idea what's going on, I ripped this straight from
    // the datasheet. See section 3.11.3 :)

    // Temperature
    var1t = ((((rawTemp>>3) - ((int32_t)calibData.T1<<1))) 
            * ((int32_t)calibData.T2)) >> 11;
    var2t = (((((rawTemp>>4) - ((int32_t)calibData.T1)) 
            * ((rawTemp>>4) - ((int32_t)calibData.T1))) >> 12) 
            * ((int32_t)calibData.T3)) >> 14;
    tFine = var1t + var2t;
    
    out.temperature = (tFine * 5 + 128) >> 8;
    
    // Pressure
    var1p = ((int64_t)tFine) - 128000;
    var2p = var1p * var1p * (int64_t)calibData.P6;
    var2p = var2p + ((var1p*(int64_t)calibData.P5)<<17);
    var2p = var2p + (((int64_t)calibData.P4)<<35);
    var1p = ((var1p * var1p * (int64_t)calibData.P3)>>8)
             + ((var1p * (int64_t)calibData.P2)<<12);
    var1p = (((((int64_t)1)<<47)+var1p)) * ((int64_t)calibData.P1)>>33;
    if (var1p == 0)
    {
        out.pressure = 0; // avoid exception caused by division by zero
    } else {
        p = 1048576-rawPress;
        p = (((p<<31)-var2p)*3125)/var1p;
        var1p = (((int64_t)calibData.P9) * (p>>13) * (p>>13)) >> 25;
        var2p = (((int64_t)calibData.P8) * p) >> 19;
        p = ((p + var1p + var2p) >> 8) + (((int64_t)calibData.P7)<<4);
        out.pressure = p;
    }

    return out;
}

BaroStatus BARO_READ_STATUS(){
    uint8_t data;
    BaroStatus out;
    select();
    readAddr(ADDR_STATUS, &data, 1);
    unselect();

    out.isConverting = (data&0x08) == 0x08;
    out.isCopying    = data&0x01;
    return out;
}

void RELOAD_CONFIG(){
    uint8_t raw;
    select();
    readAddr(ADDR_CONFIG, &raw, 1);
    unselect();
    m_tStandby = raw & 0xE0;
    m_filterCoeff = raw & 0x1C;
}
void RELOAD_SAMPLING_OPTIONS(){
    uint8_t raw;
    select();
    readAddr(ADDR_CTRL_MEAS, &raw, 1);
    unselect();
    m_tempOSR = raw & 0xE0;
    m_pressOSR = raw & 0x1C;
    m_mode = raw & 0x03;
}

static void loadCalibrationData(){
    select();
    readAddr(ADDR_CALIB_START, (uint8_t*)(&calibData.T1), 24);
    unselect();
}

// Write functions

void SET_SAMPLING_OPTIONS(uint8_t oversampTemp, uint8_t oversampPress, uint8_t powerMode){
    select();
    writeAddr(ADDR_CTRL_MEAS, oversampTemp | oversampPress | powerMode);
    unselect();
    m_pressOSR = oversampPress;
    m_tempOSR = oversampTemp;
    m_mode = powerMode;
}
void SET_POWERMODE(uint8_t powerMode){
    select();
    writeAddr(ADDR_CTRL_MEAS, m_tempOSR|m_pressOSR|powerMode);
    unselect();
    m_mode = powerMode;
}
void SET_CONFIG(uint8_t timeStandby, uint8_t filterCoeff){
    select();
    writeAddr(ADDR_CONFIG, timeStandby|filterCoeff);
    unselect();
    m_tStandby = timeStandby;
    m_filterCoeff = filterCoeff;
}

// Infrastructure
static void select(){
    HAL_GPIO_WritePin(PORT, PIN, LOW);
}
static void unselect(){
    HAL_GPIO_WritePin(PORT, PIN, HIGH);
}
static void readAddr(uint8_t addr, uint8_t* outBuff, int numBytes){
    addr = READ | addr;
    HAL_SPI_Transmit(b_hspi, &addr, 1, 100);
    HAL_SPI_Receive(b_hspi, outBuff, numBytes, 100);
}
static void writeAddr(uint8_t addr, uint8_t data){
    uint8_t message[] = {WRITE&addr, data};
    HAL_SPI_Transmit(b_hspi, message, 2, 100);
}
