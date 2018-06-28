#include <xc.h>
#include "header.h"
#include "mcc_generated_files/mcc.h"

void main(void) {

    SYSTEM_Initialize();
    initI2C();
    initRW1063();
    INTERRUPT_GlobalInterruptDisable();
    INTERRUPT_PeripheralInterruptDisable();
    uint16_t PWM1 = 0;
    uint16_t PWM2 = 0;
    uint16_t PWM3 = 0;
    writeInst(0b00000001);
    __delay_ms(40);
    initRTC();
    uint8_t i=0;
    uint8_t second = 0;
    uint8_t minute = 0;
    uint8_t heure = 0;
    uint8_t uniteS = 0;
    uint8_t dizaineS = 0;
    uint8_t uniteM = 0;
    uint8_t dizaineM = 0;
    uint8_t uniteH = 0;
    uint8_t dizaineH = 0;
    uint8_t bufferS = 0;
    uint8_t bufferM = 0;
    uint8_t bufferH = 0;
    uint8_t menu = 0;
    uint8_t select = 0;
    while (1) {
        /*
         writeData(150,0x01,0x01);
         writeData(150,0x01,0x02);
        
         writeData(240,0x02,0x01);
         writeData(240,0x02,0x02);
         writeData(240,0x02,0x03);
         writeData(240,0x02,0x04);
        
         writeData(10,0x03,0x01);
         */
        /*
        PWM1+=readData(0x01,0x01);
        PWM1+=readData(0x01,0x02);
        
        PWM2+=readData(0x02,0x01);
        PWM2+=readData(0x02,0x02);
        PWM2+=readData(0x02,0x03);
        PWM2+=readData(0x02,0x04);
        
        PWM3+=readData(0x03,0x01);
         */
        while (1) {
            
            second = readSec(); //lecture des secondes
            minute = readMin(); //lecture des minutes
            heure = readHr(); //lecture des heures

            second = second - 0b10000000; //on retire � la lecture des secondes le bit de lancement de l'oscillateur

            uniteS = bitExtracted(second, 4, 1); //on extrait l'unit� des secondes
            dizaineS = bitExtracted(second, 3, 5); //on extrait les dizaines de secondes

            uniteM = bitExtracted(minute, 4, 1); //on extrait l'unit� des minutes
            dizaineM = bitExtracted(minute, 3, 5); //on extrait les dizaines de minutes

            uniteH = bitExtracted(heure, 4, 1); //on extrait l'unit� des heures
            dizaineH = bitExtracted(heure, 2, 5); //on extrait les dizaines d'heures

            bufferS = convertFromBcd(second); //on convertit en d�cimal classique pour le d�bugger
            bufferM = convertFromBcd(minute); //on convertit en d�cimal classique pour le d�bugger
            bufferH = convertFromBcd(heure); //on convertit en d�cimal classique pour le d�bugger
            
            PWM1_LoadDutyValue(300 + i / 4);
            PWM2_LoadDutyValue(960 - i);
            PWM3_LoadDutyValue(10 + i / 10);
            if (menu == 0) {
                writeLCD(FSM(dizaineS), 6, 1); //�criture des dizaines de secondes
                writeLCD(FSM(uniteS), 7, 1); //�criture des unit�s de secondes
                writeLCD(FSM(dizaineM), 3, 1); //�criture des dizaines de minutes
                writeLCD(FSM(uniteM), 4, 1); //�criture des unit� de minutes
                writeLCD(FSM(dizaineH), 0, 1); //�criture des dizaines d'heure
                writeLCD(FSM(uniteH), 1, 1); //�criture des unit�s d'heure
                writeLCD(':', 2, 1); //�criture de la s�paration
                writeLCD(':', 5, 1); //�criture de la s�paration
            }
            if (Button1_GetValue() == 0) {
                menu = 1;
                while (Button1_GetValue() == 0);
            }
            if (menu == 1) {
                __delay_ms(100);
                if (Button1_GetValue() == 0) {
                    ++select;
                    if (select == 1) {
                        printReglageH();
                    }
                    if (select == 2) {
                        writeInst(0b00000001);
                        menu = 0;
                        select = 0;
                    }
                    while (Button1_GetValue() == 0);
                }
                if (Button2_GetValue() == 0) {
                    incrMin();
                    printReglageH();
                    //writeInst(0b00000001);
                    //writeData('A', 1, 1);
                }
                if (Button3_GetValue() == 0) {
                    incrHeure();
                    printReglageH();
                    //writeInst(0b00000001);
                    //writeData('B',1,1);
                }
            }
         
        }
    }
}
