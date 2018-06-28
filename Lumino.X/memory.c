#include "header.h"
#include "head_memory.h"


void tempo()
{
    int i = 0; 
        for (i = 0; i < 5; i++) {
        __delay_ms(1);
    }
}
uint8_t writeData(uint8_t value, uint8_t HA, uint8_t LA)
{
    tempo();
   
    //******WRITE******//
    startI2C();
    
    sendI2C(0b10100000); //Envoie adresse 1010 000 + 0, bit d'ecriture    

    sendI2C(HA);

    sendI2C(LA);

    sendI2C(value);
  
    stopI2C();  
    
    tempo();
}
uint8_t readData(uint8_t HA, uint8_t LA)
{
    startI2C();
    
    sendI2C(0b10100000); //Envoie adresse 1010 000 + 0, bit d'ecriture 

    sendI2C(HA);

    sendI2C(LA);

    re_startI2C();
    
    sendI2C(0b10100001);//Envoie adresse 1010 100 + 1, bit de lecture

    uint8_t result = readI2C();
    
    sendNoAckI2C();
    
    stopI2C();

    return result;
}
uint8_t getData()
{
    uint8_t value = 0b11111000;
    uint8_t result;
    tempo();
   
    //******WRITE******//
    startI2C();
    
    sendI2C(0b10100000); //Envoie adresse 1010 000 + 0, bit d'ecriture    

    sendI2C(0x12);

    sendI2C(0x55);

    sendI2C(value);
  
    stopI2C();  
    
    tempo();
    //******READ******//
    startI2C();
    
    sendI2C(0b10100000); //Envoie adresse 1010 000 + 0, bit d'ecriture 

    sendI2C(0x12);

    sendI2C(0x55);

    re_startI2C();
    
    sendI2C(0b10100001);//Envoie adresse 1010 100 + 1, bit de lecture

    result = readI2C();
    
    sendNoAckI2C();
    
    stopI2C();

    return result;
}
