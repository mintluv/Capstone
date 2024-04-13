/*
 * MPU9250.c
 *
 *  Created on: Mar 13, 2022
 *      Author: MarkSherstan
 */

#include "MPU9250.h"
static uint8_t _mag_adjust[3];
static uint8_t buf[21];
// MPU9250 registers
const uint8_t ACCEL_OUT = 0x3B;
const uint8_t GYRO_OUT = 0x43;
const uint8_t TEMP_OUT = 0x41;
const uint8_t EXT_SENS_DATA_00 = 0x49;
const uint8_t ACCEL_FS_SEL_2G = 0x00;
const uint8_t ACCEL_FS_SEL_4G = 0x08;
const uint8_t ACCEL_FS_SEL_8G = 0x10;
const uint8_t ACCEL_FS_SEL_16G = 0x18;
const uint8_t GYRO_FS_SEL_250DPS = 0x00;
const uint8_t GYRO_FS_SEL_500DPS = 0x08;
const uint8_t GYRO_FS_SEL_1000DPS = 0x10;
const uint8_t GYRO_FS_SEL_2000DPS = 0x18;
const uint8_t ACCEL_CONFIG2 = 0x1D;
const uint8_t DLPF_184 = 0x01;
const uint8_t DLPF_92 = 0x02;
const uint8_t DLPF_41 = 0x03;
const uint8_t DLPF_20 = 0x04;
const uint8_t DLPF_10 = 0x05;
const uint8_t DLPF_5 = 0x06;
const uint8_t CONFIG = 0x1A;
const uint8_t SMPDIV = 0x19;
const uint8_t INT_PIN_CFG = 0x37;
const uint8_t INT_ENABLE = 0x38;
const uint8_t INT_DISABLE = 0x00;
const uint8_t INT_PULSE_50US = 0x00;
const uint8_t INT_WOM_EN = 0x40;
const uint8_t INT_RAW_RDY_EN = 0x01;
const uint8_t PWR_MGMNT_1 = 0x6B;
const uint8_t PWR_CYCLE = 0x20;
const uint8_t PWR_RESET = 0x80;
const uint8_t CLOCK_SEL_PLL = 0x01;
const uint8_t PWR_MGMNT_2 = 0x6C;
const uint8_t SEN_ENABLE = 0x00;
const uint8_t DIS_GYRO = 0x07;
const uint8_t I2C_MST_EN = 0x20;
const uint8_t I2C_MST_CLK = 0x0D;
const uint8_t I2C_MST_CTRL = 0x24;
const uint8_t I2C_SLV0_ADDR = 0x25;
const uint8_t I2C_SLV0_REG = 0x26;
const uint8_t I2C_SLV0_DO = 0x63;
const uint8_t I2C_SLV0_CTRL = 0x27;
const uint8_t I2C_SLV0_EN = 0x80;
const uint8_t I2C_READ_FLAG = 0x80;
const uint8_t MOT_DETECT_CTRL = 0x69;
const uint8_t ACCEL_INTEL_EN = 0x80;
const uint8_t ACCEL_INTEL_MODE = 0x40;
const uint8_t LP_ACCEL_ODR = 0x1E;
const uint8_t WOM_THR = 0x1F;
const uint8_t FIFO_EN = 0x23;
const uint8_t FIFO_TEMP = 0x80;
const uint8_t FIFO_GYRO = 0x70;
const uint8_t FIFO_ACCEL = 0x08;
const uint8_t FIFO_MAG = 0x01;
const uint8_t FIFO_COUNT = 0x72;
const uint8_t FIFO_READ = 0x74;

// AK8963 registers
const uint8_t AK8963_I2C_ADDR = 0x0C;
const uint8_t AK8963_HXL = 0x03;
const uint8_t AK8963_CNTL1 = 0x0A;
const uint8_t AK8963_PWR_DOWN = 0x00;
const uint8_t AK8963_CNT_MEAS1 = 0x12;
const uint8_t AK8963_CNT_MEAS2 = 0x16;
const uint8_t AK8963_FUSE_ROM = 0x0F;
const uint8_t AK8963_CNTL2 = 0x0B;
const uint8_t AK8963_RESET = 0x01;
const uint8_t AK8963_ASA = 0x10;
const uint8_t AK8963_WHO_AM_I = 0x00;
void writeAK8963Register(SPI_HandleTypeDef *SPIx, MPU9250_t *pMPU9250, uint8_t subAddress, uint8_t data)
{
    uint8_t  addr, val;

	// set slave 0 to the AK8963 and set for write
    addr = I2C_SLV0_ADDR;
    val = AK8963_I2C_ADDR;
	MPU_REG_WRITE(SPIx, pMPU9250,&addr,&val);
    addr = I2C_SLV0_REG;
    val = subAddress;
	// set the register to the desired AK8963 sub address
	MPU_REG_WRITE(SPIx, pMPU9250,&addr,&val);
    addr = I2C_SLV0_DO;
    val = data;
	// store the data for write
	MPU_REG_WRITE(SPIx, pMPU9250,&addr,&val);
    addr = I2C_SLV0_CTRL;
    val = (I2C_SLV0_EN | (uint8_t)1);
	// enable I2C and send 1 byte
	MPU_REG_WRITE(SPIx, pMPU9250,&addr,&val);
}

/* reads registers from the AK8963 */
void readAK8963Registers(SPI_HandleTypeDef *SPIx, MPU9250_t *pMPU9250, uint8_t subAddress, uint8_t count, uint8_t* dest)
{
    uint8_t addr, val;
	// set slave 0 to the AK8963 and set for read
    addr = I2C_SLV0_ADDR;
    val = (AK8963_I2C_ADDR | I2C_READ_FLAG);
	MPU_REG_WRITE(SPIx, pMPU9250,&addr, &val);

    addr = I2C_SLV0_REG;
    val = subAddress;
	// set the register to the desired AK8963 sub address
	MPU_REG_WRITE(SPIx, pMPU9250,&addr,&val);

    addr = I2C_SLV0_CTRL;
    val = (I2C_SLV0_EN | count);
	// enable I2C and request the bytes
	MPU_REG_WRITE(SPIx, pMPU9250,&addr,&val);

	// takes some time for these registers to fill
	HAL_Delay(1);
    addr = EXT_SENS_DATA_00;
	// read the bytes off the MPU9250 EXT_SENS_DATA registers
	MPU_REG_READ(SPIx, pMPU9250, addr,dest,count);
}


/// @brief Check for connection, reset IMU, and set full range scale
/// @param SPIx Pointer to SPI structure config
/// @param pMPU9250 Pointer to master MPU9250 struct

uint8_t MPU_begin(SPI_HandleTypeDef *SPIx, MPU9250_t *pMPU9250)
{
    // Initialize variables
    uint8_t check, addr, val;

    // Confirm device
    MPU_REG_READ(SPIx, pMPU9250, WHO_AM_I, &check, 1);
    if (check == WHO_AM_I_9250_ANS)
    {
        // Startup / reset the sensor
        addr = PWR_MGMT_1;
        val = 0x00;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr, &val);

        // Disable I2C (SPI only)
        addr = USER_CTRL;
        val = 0x10;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr, &val);
        writeAK8963Register(SPIx, pMPU9250, AK8963_CNTL2,AK8963_RESET);
        val =I2C_MST_EN;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr,&val);

        readAK8963Registers(SPIx, pMPU9250, AK8963_WHO_AM_I, 1, &check);
        	// return the register value
        if (check != 0x48){
            printf("error");
            return 0;
        }
	    /* get the magnetometer calibration */
	    // set AK8963 to Power Down
	    writeAK8963Register(SPIx, pMPU9250, AK8963_CNTL1,AK8963_PWR_DOWN);

	    HAL_Delay(100); // long wait between AK8963 mode changes

	    // set AK8963 to FUSE ROM access
	    writeAK8963Register(SPIx, pMPU9250, AK8963_CNTL1,AK8963_FUSE_ROM);

	    // long wait between AK8963 mode changes
	    HAL_Delay(100);

	    // read the AK8963 ASA registers and compute magnetometer scale factors
	    readAK8963Registers(SPIx, pMPU9250, AK8963_ASA, 3, _mag_adjust);

	    // set AK8963 to Power Down
	    writeAK8963Register(SPIx, pMPU9250, AK8963_CNTL1,AK8963_PWR_DOWN);

	    // long wait between AK8963 mode changes
	    HAL_Delay(100);

	    // set AK8963 to 16 bit resolution, 100 Hz update rate
	    writeAK8963Register(SPIx, pMPU9250, AK8963_CNTL1,AK8963_CNT_MEAS2);

	    // long wait between AK8963 mode changes
	    HAL_Delay(100);
	    readAK8963Registers(SPIx, pMPU9250,1,1,buf);
        readAK8963Registers(SPIx, pMPU9250,AK8963_HXL,7,buf);
        
        // Set the full scale ranges
        MPU_writeAccFullScaleRange(SPIx, pMPU9250, pMPU9250->settings.aFullScaleRange);
        MPU_writeGyroFullScaleRange(SPIx, pMPU9250, pMPU9250->settings.gFullScaleRange);
        return 1;
        
    }
    else
    {
        return 0;
    }
}


/* writes a register to the AK8963 given a register address and data */


/// @brief Read a specific registry address
/// @param SPIx Pointer to SPI structure config
/// @param pMPU9250 Pointer to master MPU9250 struct
/// @param pAddr Pointer to address to be written to
/// @param pVal Pointer of value to write to given address
void MPU_REG_WRITE(SPI_HandleTypeDef *SPIx, MPU9250_t *pMPU9250, uint8_t *pAddr, uint8_t *pVal)
{
    MPU_CS(pMPU9250, CS_SELECT);
    HAL_SPI_Transmit(SPIx, pAddr, 1, SPI_TIMOUT_MS);
    HAL_SPI_Transmit(SPIx, pVal, 1, SPI_TIMOUT_MS);
    MPU_CS(pMPU9250, CS_DESELECT);
}

/// @brief Read a specific registry address
/// @param SPIx Pointer to SPI structure config
/// @param pMPU9250 Pointer to master MPU9250 struct
/// @param addr Address to start reading at
/// @param pRxData Pointer to data buffer
/// @param RxSize Size of data buffer
void MPU_REG_READ(SPI_HandleTypeDef *SPIx, MPU9250_t *pMPU9250, uint8_t addr, uint8_t *pRxData, uint16_t RxSize)
{
    MPU_CS(pMPU9250, CS_SELECT);
    uint8_t writeAddr = addr | READWRITE;
    HAL_SPI_Transmit(SPIx, &writeAddr, 1, SPI_TIMOUT_MS);
    HAL_SPI_Receive(SPIx, pRxData, RxSize, SPI_TIMOUT_MS);
    MPU_CS(pMPU9250, CS_DESELECT);
}

/// @brief Set CS state to either start or end transmissions
/// @param pMPU9250 Pointer to master MPU9250 struct
/// @param state Set low to select, high to deselect
void MPU_CS(MPU9250_t *pMPU9250, uint8_t state)
{
    HAL_GPIO_WritePin(pMPU9250->settings.CS_PORT, pMPU9250->settings.CS_PIN, state);
}

/// @brief Set the accelerometer full scale range
/// @param SPIx Pointer to SPI structure config
/// @param pMPU9250 Pointer to master MPU9250 struct
/// @param aScale Set 0 for ±2g, 1 for ±4g, 2 for ±8g, and 3 for ±16g
void MPU_writeAccFullScaleRange(SPI_HandleTypeDef *SPIx, MPU9250_t *pMPU9250, uint8_t aScale)
{
    // Variable init
    uint8_t addr = ACCEL_CONFIG;
    uint8_t val;

    // Set the value
    switch (aScale)
    {
    case AFSR_2G:
        pMPU9250->sensorData.aScaleFactor = 16384.0;
        val = 0x00;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr, &val);
        break;
    case AFSR_4G:
        pMPU9250->sensorData.aScaleFactor = 8192.0;
        val = 0x08;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr, &val);
        break;
    case AFSR_8G:
        pMPU9250->sensorData.aScaleFactor = 4096.0;
        val = 0x10;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr, &val);
        break;
    case AFSR_16G:
        pMPU9250->sensorData.aScaleFactor = 2048.0;
        val = 0x18;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr, &val);
        break;
    default:
        pMPU9250->sensorData.aScaleFactor = 8192.0;
        val = 0x08;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr, &val);
        break;
    }
}

/// @brief Set the gyroscope full scale range
/// @param SPIx Pointer to SPI structure config
/// @param pMPU9250 Pointer to master MPU9250 struct
/// @param gScale Set 0 for ±250°/s, 1 for ±500°/s, 2 for ±1000°/s, and 3 for ±2000°/s
void MPU_writeGyroFullScaleRange(SPI_HandleTypeDef *SPIx, MPU9250_t *pMPU9250, uint8_t gScale)
{
    // Variable init
    uint8_t addr = GYRO_CONFIG;
    uint8_t val;

    // Set the value
    switch (gScale)
    {
    case GFSR_250DPS:
        pMPU9250->sensorData.gScaleFactor = 131.0;
        val = 0x00;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr, &val);
        break;
    case GFSR_500DPS:
        pMPU9250->sensorData.gScaleFactor = 65.5;
        val = 0x08;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr, &val);
        break;
    case GFSR_1000DPS:
        pMPU9250->sensorData.gScaleFactor = 32.8;
        val = 0x10;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr, &val);
        break;
    case GFSR_2000DPS:
        pMPU9250->sensorData.gScaleFactor = 16.4;
        val = 0x18;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr, &val);
        break;
    default:
        pMPU9250->sensorData.gScaleFactor = 65.5;
        val = 0x08;
        MPU_REG_WRITE(SPIx, pMPU9250, &addr, &val);
        break;
    }
}

/// @brief Read raw data from IMU
/// @param SPIx Pointer to SPI structure config
/// @param pMPU9250 Pointer to master MPU9250 struct
void MPU_readRawData(SPI_HandleTypeDef *SPIx, MPU9250_t *pMPU9250)
{
    // Init buffer
    

    // Subroutine for reading the raw data
    MPU_REG_READ(SPIx, pMPU9250, ACCEL_XOUT_H, &buf[0], 21);

    // Bit shift the data
    pMPU9250->rawData.ax = buf[0] << 8 | buf[1];
    pMPU9250->rawData.ay = buf[2] << 8 | buf[3];
    pMPU9250->rawData.az = buf[4] << 8 | buf[5];
    // temperature = buf[6] << 8 | buf[7];
    pMPU9250->rawData.gx = buf[8] << 8 | buf[9];
    pMPU9250->rawData.gy = buf[10] << 8 | buf[11];
    pMPU9250->rawData.gz = buf[12] << 8 | buf[13];

    int16_t magx = (((int16_t)buf[15]) << 8) | buf[14];
	int16_t magy = (((int16_t)buf[17]) << 8) | buf[16];
	int16_t magz = (((int16_t)buf[19]) << 8) | buf[18];

    pMPU9250->rawData.mx = (int16_t)((float)magx * ((float)(_mag_adjust[0] - 128) / 256.0f + 1.0f));
	pMPU9250->rawData.my = (int16_t)((float)magy * ((float)(_mag_adjust[1] - 128) / 256.0f + 1.0f));
	pMPU9250->rawData.mz = (int16_t)((float)magz * ((float)(_mag_adjust[2] - 128) / 256.0f + 1.0f));
}

/// @brief Find offsets for each axis of gyroscope
/// @param SPIx Pointer to SPI structure config
/// @param pMPU9250 Pointer to master MPU9250 struct
/// @param numCalPoints Number of data points to average
void MPU_calibrateGyro(SPI_HandleTypeDef *SPIx, MPU9250_t *pMPU9250, uint16_t numCalPoints)
{
    // Init
    int32_t x = 0;
    int32_t y = 0;
    int32_t z = 0;

    // Zero guard
    if (numCalPoints == 0)
    {
        numCalPoints = 1;
    }

    // Save specified number of points
    for (uint16_t ii = 0; ii < numCalPoints; ii++)
    {
        MPU_readRawData(SPIx, pMPU9250);
        x += pMPU9250->rawData.gx;
        y += pMPU9250->rawData.gy;
        z += pMPU9250->rawData.gz;
        HAL_Delay(3);
    }

    // Average the saved data points to find the gyroscope offset
    pMPU9250->gyroCal.x = (float)x / (float)numCalPoints;
    pMPU9250->gyroCal.y = (float)y / (float)numCalPoints;
    pMPU9250->gyroCal.z = (float)z / (float)numCalPoints;
}

/// @brief Calculate the real world sensor values
/// @param SPIx Pointer to SPI structure config
/// @param pMPU9250 Pointer to master MPU9250 struct
void MPU_readProcessedData(SPI_HandleTypeDef *SPIx, MPU9250_t *pMPU9250)
{
    // Get raw values from the IMU
    MPU_readRawData(SPIx, pMPU9250);

    // Convert accelerometer values to g's
    pMPU9250->sensorData.ax = pMPU9250->rawData.ax / pMPU9250->sensorData.aScaleFactor;
    pMPU9250->sensorData.ay = pMPU9250->rawData.ay / pMPU9250->sensorData.aScaleFactor;
    pMPU9250->sensorData.az = pMPU9250->rawData.az / pMPU9250->sensorData.aScaleFactor;

    // Compensate for gyro offset
    pMPU9250->sensorData.gx = pMPU9250->rawData.gx - pMPU9250->gyroCal.x;
    pMPU9250->sensorData.gy = pMPU9250->rawData.gy - pMPU9250->gyroCal.y;
    pMPU9250->sensorData.gz = pMPU9250->rawData.gz - pMPU9250->gyroCal.z;

    // Convert gyro values to deg/s
    pMPU9250->sensorData.gx /= pMPU9250->sensorData.gScaleFactor;
    pMPU9250->sensorData.gy /= pMPU9250->sensorData.gScaleFactor;
    pMPU9250->sensorData.gz /= pMPU9250->sensorData.gScaleFactor;
}

/// @brief Calculate the attitude of the sensor in degrees using a complementary filter
/// @param SPIx Pointer to SPI structure config
/// @param pMPU9250 Pointer to master MPU9250 struct
void MPU_calcAttitude(SPI_HandleTypeDef *SPIx, MPU9250_t *pMPU9250)
{
    // Read processed data
    MPU_readProcessedData(SPIx, pMPU9250);

    // Complementary filter
    float accelPitch = atan2(pMPU9250->sensorData.ay, pMPU9250->sensorData.az) * RAD2DEG;
    float accelRoll = atan2(pMPU9250->sensorData.ax, pMPU9250->sensorData.az) * RAD2DEG;

    pMPU9250->attitude.r = pMPU9250->attitude.tau * (pMPU9250->attitude.r - pMPU9250->sensorData.gy * pMPU9250->attitude.dt) + (1 - pMPU9250->attitude.tau) * accelRoll;
    pMPU9250->attitude.p = pMPU9250->attitude.tau * (pMPU9250->attitude.p - pMPU9250->sensorData.gx * pMPU9250->attitude.dt) + (1 - pMPU9250->attitude.tau) * accelPitch;
    pMPU9250->attitude.y += (pMPU9250->sensorData.gz * pMPU9250->attitude.dt);
}
