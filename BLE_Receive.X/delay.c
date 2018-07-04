
#include "header.h"
#include "mcc_generated_files/mcc.h"



void delay_ms(int msec){
    TMR1_StartTimer();
    TMR1_Reload();
    TMR1IF = 0;
    for (int x = 0; x < msec; x++){
        while(!TMR1IF);
        TMR1_Reload();
        TMR1IF = 0;
    }
    TMR1_StopTimer();
}