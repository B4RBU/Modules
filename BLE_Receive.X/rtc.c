/*
 * File:   rtc.c
 * Author: Alex
 *
 * Created on July 5, 2018, 3:50 PM
 */


#include <xc.h>
#include "rtc4.h"

void initRTC() {
    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x00);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0b10000000);
    while (SSP1CON2bits.ACKSTAT == 1);
    stopI2C();

    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x01);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0b01001000);
    while (SSP1CON2bits.ACKSTAT == 1);
    stopI2C();

    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x02);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0b00010100);
    while (SSP1CON2bits.ACKSTAT == 1);
    stopI2C();
}

void changeMin(uint8_t minute)
{
    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x01);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(minute);
    while (SSP1CON2bits.ACKSTAT == 1);
    stopI2C();
}

void changeHeure(uint8_t heure)
{
    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x02);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(heure);
    while (SSP1CON2bits.ACKSTAT == 1);
    stopI2C();
}

uint8_t readSec() {
    uint8_t second = 0;
    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x00);
    while (SSP1CON2bits.ACKSTAT == 1);
    re_startI2C();
    sendI2C(0b11011111);
    while (SSP1CON2bits.ACKSTAT == 1);
    second = readI2C();
    sendNoAckI2C();
    stopI2C();
    return second;
}

uint8_t readMin() {
    uint8_t minute = 0;
    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x01);
    while (SSP1CON2bits.ACKSTAT == 1);
    re_startI2C();
    sendI2C(0b11011111);
    while (SSP1CON2bits.ACKSTAT == 1);
    minute = readI2C();
    sendNoAckI2C();
    stopI2C();
    return minute;
}

uint8_t readHr() {
    uint8_t heure = 0;
    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x02);
    while (SSP1CON2bits.ACKSTAT == 1);
    re_startI2C();
    sendI2C(0b11011111);
    while (SSP1CON2bits.ACKSTAT == 1);
    heure = readI2C();
    sendNoAckI2C();
    stopI2C();
    return heure;
}



void incrMin()
{
    uint8_t minute=0;
    uint8_t dizaineM=0;
    uint8_t uniteM=0;
    minute = readMin(); //lecture des minutes
    uniteM = bitExtracted(minute, 4, 1); //on extrait l'unité des minutes
    dizaineM = bitExtracted(minute, 3, 5); //on extrait les dizaines de minutes
    minute=0;
    uniteM=uniteM+1;
    if(uniteM>9)
    {
        uniteM=0;
        dizaineM=dizaineM+1;
    }
    if(dizaineM>6)
    {
        dizaineM=0;
        uniteM=0;
    }
    minute=minute+dizaineM;
    minute=minute<<4;
    minute=minute+uniteM;
    changeMin(minute);
}

void incrHeure()
{
    uint8_t heure=0;
    uint8_t dizaineH=0;
    uint8_t uniteH=0;
    heure = readHr(); //lecture des heures
    uniteH = bitExtracted(heure, 4, 1); //on extrait l'unité des heures
    dizaineH = bitExtracted(heure, 2, 5); //on extrait les dizaines d'heures
    heure=0;
    uniteH=uniteH+1;
    if(uniteH>9)
    {
        uniteH=0;
        dizaineH=dizaineH+1;
    }
    if(dizaineH>2 && uniteH==4)
    {
        dizaineH=0;
        uniteH=uniteH+1;
    }
    heure=heure+dizaineH;
    heure=heure<<4;
    heure=heure+uniteH;
    changeHeure(heure);
}