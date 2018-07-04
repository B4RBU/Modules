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
    
    
   
    
    
   
    init_B();
while (1){    
    
    k = ReturnReg();
  
        if (k == '$'){
    LED1 = !LED1;
    LED2 = !LED2;
    LED3 = !LED3;
    LED4 = !LED4;
    delay_ms(1000);





    
}
}
}