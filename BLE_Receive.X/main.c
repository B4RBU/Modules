#include "header.h"
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>









void main(void) {
    
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    uint8_t Bt = 0;
    
    LED1 = 0;
    LED2 = 0;
    LED3 = 0;
    LED4 = 0;
    int k =0 ;
    
    
   
    
    
    initI2C();
    initRTC();
    init_B();
    
    
    remote();
    delay_ms(1000);
    remote();
    delay_ms(1000);
    remote();
    delay_ms(1000);
while (1){    
    
    k = ReturnReg();
  
        if (k == '$'){
    LED1 = !LED1;
    LED2 = !LED2;
    LED3 = !LED3;
    LED4 = !LED4;
    delay_ms(1000);
     }
     
    
    if ( bouton_GetValue() ==  0) 
    {
    
          //  Bt = 1;
            LED1 = 1 ;
    EUSART_Write('$');
    
    
    
    EUSART_Write(10);
    EUSART_Write(13);
   
            
            
                   
    
    }
    else if (bouton_GetValue() == 1)
        {
           // Bt = 0;
            LED1=0;
           // EUSART_Write('é');
    
    
    
   // EUSART_Write(10);
   // EUSART_Write(13);
    
            
            
        }
    




    
}
}