#include <xc.h>
#include "header.h"
#include "mcc_generated_files/mcc.h"

void main(void) {

    SYSTEM_Initialize();
    initI2C();
    initRW1063();
    //INTERRUPT_GlobalInterruptEnable();
    //INTERRUPT_PeripheralInterruptEnable();
    INTERRUPT_GlobalInterruptDisable();
    INTERRUPT_PeripheralInterruptDisable();
    writeInst(0b00000001);
    __delay_ms(40);
    //initRTC();
    uint8_t second = 0;
    uint8_t minute = 0;
    uint8_t heure = 0;
    uint8_t uniteS = 0;
    uint8_t dizaineS = 0;
    uint8_t uniteM = 0;
    uint8_t dizaineM = 0;
    uint8_t uniteH = 0;
    uint8_t dizaineH = 0;
    uint8_t buffer = 0;
    uint8_t menu = 0;
    uint8_t select=0;
    while (1) {
        second = readSec(); //lecture des secondes
        minute = readMin(); //lecture des minutes
        heure = readHr(); //lecture des heures

        second = second - 0b10000000; //on retire à la lecture des secondes le bit de lancement de l'oscillateur

        uniteS = bitExtracted(second, 4, 1); //on extrait l'unité des secondes
        dizaineS = bitExtracted(second, 3, 5); //on extrait les dizaines de secondes

        uniteM = bitExtracted(minute, 4, 1); //on extrait l'unité des minutes
        dizaineM = bitExtracted(minute, 3, 5); //on extrait les dizaines de minutes

        uniteH = bitExtracted(heure, 4, 1); //on extrait l'unité des heures
        dizaineH = bitExtracted(heure, 2, 5); //on extrait les dizaines d'heures

        buffer = convertFromBcd(second); //on convertit en décimal classique pour le débugger
        buffer = convertFromBcd(minute); //on convertit en décimal classique pour le débugger
        buffer = convertFromBcd(heure); //on convertit en décimal classique pour le débugger
        if (menu == 0) 
        {
            writeData(FSM(dizaineS), 6, 1); //écriture des dizaines de secondes
            writeData(FSM(uniteS), 7, 1); //écriture des unités de secondes
            writeData(FSM(dizaineM), 3, 1); //écriture des dizaines de minutes
            writeData(FSM(uniteM), 4, 1); //écriture des unité de minutes
            writeData(FSM(dizaineH), 0, 1); //écriture des dizaines d'heure
            writeData(FSM(uniteH), 1, 1); //écriture des unités d'heure
            writeData(':', 2, 1); //écriture de la séparation
            writeData(':', 5, 1); //écriture de la séparation
        }
        if (Button1_GetValue() == 1) 
        {
            menu = 1;
            while(Button1_GetValue()==1);
        }
        if (menu == 1) 
        {
            __delay_ms(100);
            if(Button1_GetValue()==1)
            {
                ++select;
                if(select==1)
                {
                    printReglageH();
                }
                if(select==2)
                {
                    writeInst(0b00000001);
                    menu=0;
                    select=0;
                }
                while(Button1_GetValue()==1);
            }
            if (Button2_GetValue() == 1) 
            {
                incrMin();
                printReglageH();
                //writeInst(0b00000001);
                //writeData('A', 1, 1);
            }
            if (Button3_GetValue()==1)
            {
                incrHeure();
                printReglageH();
                //writeInst(0b00000001);
                //writeData('B',1,1);
            }
        }
    }
}
