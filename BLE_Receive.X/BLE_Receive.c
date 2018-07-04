#include "header.h"
#include "mcc_generated_files/mcc.h"




void Partiel_Reset()
{ 
    
    EUSART_Write('S');
    EUSART_Write('F');
    EUSART_Write(',');
    EUSART_Write('1');
    
    EUSART_Write(13);
    EUSART_Write(10);
    
}

void Set_Features()
{
    EUSART_Write('S');
    EUSART_Write('R');
    EUSART_Write(',');
    
    EUSART_Write('3');
    EUSART_Write('2');
    EUSART_Write('0');
    EUSART_Write('0');
    EUSART_Write('0');
    EUSART_Write('0');
    EUSART_Write('0');
    EUSART_Write('0');
    
    EUSART_Write(13);
    EUSART_Write(10);
}

void Set_Mode()
{   
    
    EUSART_Write('S');
    EUSART_Write('S');
    EUSART_Write(',');
    EUSART_Write('3');
    EUSART_Write('0');
    EUSART_Write('0');
    EUSART_Write('0');
    EUSART_Write('0');
    EUSART_Write('0');
    EUSART_Write('0');
    EUSART_Write('0');
    
    
    EUSART_Write(13);
    EUSART_Write(10);
}


void Reboot()
{
    EUSART_Write('R');
    EUSART_Write(',');
    EUSART_Write('1');
    
    EUSART_Write(13);
    EUSART_Write(10);
}

void Turn_On()
{
    EUSART_Write('+');
    
    EUSART_Write(13);
    EUSART_Write(10);
}

int Verif_Erreur(char * buf, unsigned int size)

{
    unsigned int i = 0;
    int j = 0;
    do{
        delay_ms(5); 
        j++;
        if (j == 10) return -1; // wait too long
    }while (eusartRxCount <= 0); // wait for data
    //if (!EUSART_DataReady) return -1; // timeout data reception
    while (eusartRxCount > 0){
        buf[i] = EUSART_Read();
        i++;
        if (i == size){
            while (eusartRxCount > 0){
                EUSART_Read();
               if (eusartRxCount == 0) delay_ms(5);
            }
            return -2; // buffer to small
        }
        delay_ms(1);
        if (eusartRxCount == 0)  delay_ms(4); // wait for more data
    }
    return j;
}


void init_B()
{
    unsigned char error = 0;
    char buf [BUF_LEN] = {0}; 
    
    IO_RC0_SetHigh();
    
    Turn_On();
    error = Verif_Erreur(buf,BUF_LEN);
    
    delay_ms(1000);
    
    Partiel_Reset();
    error = Verif_Erreur(buf,BUF_LEN);
    
    Set_Mode();
    error = Verif_Erreur(buf,BUF_LEN);
    
    Set_Features();
    error = Verif_Erreur(buf,BUF_LEN);
    
    Reboot();
    error = Verif_Erreur(buf,BUF_LEN);
    
    delay_ms(1000);
}


char ReturnReg(){
    return RCREG;
    
}