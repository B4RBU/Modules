#include "header.h"
#include "mcc_generated_files/mcc.h"
void Scan()
{
    EUSART_Write('F');
    EUSART_Write(13);
    EUSART_Write(10);    
    
    
    
    
    
    
}
void StopScan()
{
    EUSART_Write('X');
    
    EUSART_Write(13);
    EUSART_Write(10);    
    
}


void connexion()
{   
    EUSART_Write('E');
    EUSART_Write(',');
    EUSART_Write('0');
    EUSART_Write(',');
    EUSART_Write('0');
    EUSART_Write('0');
    EUSART_Write('1');
    EUSART_Write('E');
    EUSART_Write('C');
    EUSART_Write('0');
    EUSART_Write('4');
    EUSART_Write('1');
    EUSART_Write('F');
    EUSART_Write('1');
    EUSART_Write('3');
    EUSART_Write('4');
    
    EUSART_Write(13);
    EUSART_Write(10);
    
    
    delay_ms(1000);
}



void WriteOnBt(unsigned int Val)
{
    EUSART_Write ('!');
    EUSART_Write (',');
    EUSART_Write ('<');
    EUSART_Write ('0');
    EUSART_Write (',');
    EUSART_Write ('1');
    EUSART_Write ('>');
  
    
    EUSART_Write(13);
    EUSART_Write(10);
   
    
    
  
    }
void remote()
{
    EUSART_Write ('!');
    EUSART_Write (',');
    EUSART_Write ('1');
  
  
    
    EUSART_Write(13);
    EUSART_Write(10);
}
