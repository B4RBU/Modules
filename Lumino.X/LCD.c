#include "header.h"
#include "mcc_generated_files/mcc.h"


void writeInst(uint8_t Inst) {
    startI2C();
    sendI2C(0x78);
    while(SSP1CON2bits.ACKSTAT==1);
    sendI2C(0x00);
    while(SSP1CON2bits.ACKSTAT==1);
    sendI2C(Inst);
    while(SSP1CON2bits.ACKSTAT==1);
    stopI2C();
}

void writeLCD(uint8_t data, uint8_t adress, uint8_t ligne) {
    if (ligne == 2) {
        adress += 40;
    }
    for (uint8_t i = 0; i < adress; i++) {
        writeInst(0b00010100);
    }

    startI2C();
    sendI2C(0x78);
    while(SSP1CON2bits.ACKSTAT==1);
    sendI2C(0x40);
    while(SSP1CON2bits.ACKSTAT==1);
    sendI2C(data);
    while(SSP1CON2bits.ACKSTAT==1);
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
    __delay_ms(5);
    writeLCD('R', 1, 1);
    __delay_ms(1);
    writeLCD('E', 2, 1);
    __delay_ms(1);
    writeLCD('G', 3, 1);
    __delay_ms(1);
    writeLCD(' ', 4, 1);
    __delay_ms(1);
    writeLCD('H', 5, 1);
    __delay_ms(1);
    writeLCD('R', 6, 1);
    __delay_ms(1);
    minute = readMin(); //lecture des minutes
    heure = readHr(); //lecture des heures
    uniteM = bitExtracted(minute, 4, 1); //on extrait l'unité des minutes
    dizaineM = bitExtracted(minute, 3, 5); //on extrait les dizaines de minutes
    uniteH = bitExtracted(heure, 4, 1); //on extrait l'unité des heures
    dizaineH = bitExtracted(heure, 2, 5); //on extrait les dizaines d'heures
    writeLCD(FSM(dizaineM), 5, 2); //écriture des dizaines de minutes
    writeLCD(FSM(uniteM), 6, 2); //écriture des unité de minutes
    writeLCD(FSM(dizaineH), 2, 2); //écriture des dizaines d'heure
    writeLCD(FSM(uniteH), 3, 2); //écriture des unités d'heure
    writeLCD(':', 4, 2); //écriture de la séparation
}