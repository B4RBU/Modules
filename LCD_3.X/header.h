#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include "header_i2c.h"
#include "header_LCD.h"
#include "header_RTC.h"
#include "header_conversion.h"

void init(void);
void system_init(void);
void initRW1063(void);
void writeInst(uint8_t Inst);
void writeData(uint8_t data,uint8_t adress,uint8_t ligne);
void initRTC();
uint8_t bitExtracted(uint8_t number, uint8_t k, uint8_t p);
uint8_t convertFromBcd(uint8_t byteBCD);
uint8_t FSM(uint8_t IN);
uint8_t readSec();
uint8_t readMin();
uint8_t readHr();

#endif
