
#ifndef _MAIN_H_
#define _MAIN_H_


#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"


#define SPI_MISO  16
#define SPI_MOSI  20
#define SPI_SCK   19
#define SPI_SS    17

#define EINK_RES  23
#define EINK_BUSY 22
#define EINK_DC   24

#define UART_RX   6
#define UART_TX   8

#define NFC1 9
#define NFC2 10


#define EPD_RST_PIN EINK_RES
#define EPD_DC_PIN  EINK_DC
#define EPD_BUSY_PIN EINK_BUSY

typedef unsigned char  UBYTE;
typedef unsigned short UWORD;
typedef unsigned int   UDOUBLE;
//typedef unsigned char UBYTE;

#undef NRF_LOG_INFO
#define NRF_LOG_INFO(...)

#define Debug(...) NRF_LOG_INFO(__VA_ARGS__)

#define DBG(...)

void GPIO_SetBits(int pin);
void GPIO_ResetBits(int pin);

int GPIO_ReadBit(int pin);

void SdkDelayMs(int time);

void SPI_SendReceiveData(UBYTE* tx_buf, int tx_cnt);

#endif //_MAIN_H_
