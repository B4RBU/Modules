#include "mcc_generated_files/mcc.h"
#include "bluetooth.h"
#include "header.h"
#include "I2C.h"
#include "LCD.h"
#include "mcc_generated_files/pin_manager.h"


void main(void) {
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    //initI2C();
    //initRW1063();

    unsigned char error = 0;
    char buf [BUF_LEN] = {0};







    init_A();


    connexion();
    __delay_ms(1000);
    connexion();
    __delay_ms(1000);
    connexion();
    __delay_ms(1000);
    connexion();
    __delay_ms(1000);
    connexion();
    __delay_ms(1000);
    connexion();
    __delay_ms(1000);
    connexion();
    __delay_ms(1000);
    connexion();
    __delay_ms(1000);
    connexion();
    __delay_ms(1000);
    connexion();
    __delay_ms(1000);


    remote();
    __delay_ms(1000);
    uint8_t k;
    while (1) {

        k = ReturnReg();

        if (k == '$') {
            LED1_Toggle();
            LED2_Toggle();
            LED3_Toggle();
            LED4_Toggle();
            __delay_ms(1000);
        }






    



    if (boutton2_GetValue() == 0) {

        //  Bt = 1;
        LED1_SetHigh();
        EUSART_Write('$');



        EUSART_Write(10);
        EUSART_Write(13);





    } else if (boutton2_GetValue() == 1) {
        // Bt = 0;
        LED1_SetLow();
        // EUSART_Write('é');



        // EUSART_Write(10);
        // EUSART_Write(13);



    }
    // WriteOnBt(Bt);
    //error = Verif_Erreur(buf,BUF_LEN);
}
}