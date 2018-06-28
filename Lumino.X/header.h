/* 
 * File:   header.h
 * Author: axell
 *
 * Created on 29 mars 2018, 15:06
 */

#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include "header_i2c.h"
#include "head_memory.h"
#include "header_LCD.h"
#include "header_RTC.h"
#include "header_conversion.h"

#define _XTAL_FREQ 16000000//Freq Fosc pour __delay_ms(x))

void init(void);
void system_init(void);


#endif	/* XC_HEADER_TEMPLATE_H */

