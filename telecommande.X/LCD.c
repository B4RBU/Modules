/*
 * File:   LCD.c
 * Author: Alex
 *
 * Created on July 5, 2018, 11:44 AM
 */


#include <xc.h>
#include "LCD.h"

void writeInst(uint8_t Inst) {
    startI2C();
    __delay_ms(1);
    sendI2C(0x78);
    //while(SSP1CON2bits.ACKSTAT==1);
    __delay_ms(1);
    sendI2C(0x00);
    //while(SSP1CON2bits.ACKSTAT==1);
    __delay_ms(1);
    sendI2C(Inst);
    //while(SSP1CON2bits.ACKSTAT==1);
    __delay_ms(1);
    stopI2C();
}

void writeData(uint8_t data, uint8_t adress, uint8_t ligne) {
    if (ligne == 2) {
        adress += 40;
    }
    for (uint8_t i = 0; i < adress; i++) {
        writeInst(0b00010100);
    }

    startI2C();
    __delay_ms(1);
    sendI2C(0x78);
    //while(SSP1CON2bits.ACKSTAT==1);
    __delay_ms(1);
    sendI2C(0x40);
    //while(SSP1CON2bits.ACKSTAT==1);
    __delay_ms(1);
    sendI2C(data);
    //while(SSP1CON2bits.ACKSTAT==1);
    __delay_ms(1);
    stopI2C();
    writeInst(0b00000010);
}

void initRW1063() {
    writeInst(0x38);
    writeInst(0x0c);
    writeInst(0x06);
    writeInst(0b00001100);
}

void printReglageH()
{
    uint8_t minute=0;
    uint8_t heure=0;
    uint8_t dizaineM=0;
    uint8_t uniteM=0;
    uint8_t dizaineH=0;
    uint8_t uniteH=0;
    writeInst(0b00000001);
    writeData('R', 1, 1);
    writeData('E', 2, 1);
    writeData('G', 3, 1);
    writeData(' ', 4, 1);
    writeData('H', 5, 1);
    writeData('R', 6, 1);
    minute = readMin(); //lecture des minutes
    heure = readHr(); //lecture des heures
    uniteM = bitExtracted(minute, 4, 1); //on extrait l'unité des minutes
    dizaineM = bitExtracted(minute, 3, 5); //on extrait les dizaines de minutes
    uniteH = bitExtracted(heure, 4, 1); //on extrait l'unité des heures
    dizaineH = bitExtracted(heure, 2, 5); //on extrait les dizaines d'heures
    writeData(FSM(dizaineM), 5, 2); //écriture des dizaines de minutes
    writeData(FSM(uniteM), 6, 2); //écriture des unité de minutes
    writeData(FSM(dizaineH), 2, 2); //écriture des dizaines d'heure
    writeData(FSM(uniteH), 3, 2); //écriture des unités d'heure
    writeData(':', 4, 2); //écriture de la séparation
}