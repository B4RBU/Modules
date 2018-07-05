

#include <xc.h>
#include "header.h"
#include "I2C.h"
void initI2C() {
    int j = 0;
    
    //Afin d'initialiser les p�riph�riques I2C
    //Envoie de 9 coups d'horloge sur le pin SCL
    //Utile si PIC a red�marrer pendant une transmission ou reception et que le p�riphrique tient toujours la ligne SDA
    TRISB6 = 0;
    for (j = 0; j < 9; j++) {
        LATB6 = 1;
        LATB6 = 0;
    }
    
    //Configuration pin input
    TRISB6 = 1;//SCL PIN
    TRISB4 = 1;//SDA PIN

    //Mode digital port B
    ANSELB = 0x00;

    //Mise � l'�tat haut sur pin SCL et SDA
    LATB4 = 1;
    LATB6 = 1;
 
    //Registre I2C
    SSP1STAT = 0x80;//Standard Speed(100khz)
    SSP1CON1 = 0x28;//I2C master mode activ� clock = Fosc/(4*(SSP1ADD+1)) //Activation port SDA et SCL
    SSP1CON2 = 0x00;
    SSP1ADD = 0x27;//Config clock SCL � 100kHz
    
    //R�sistance pull-up SDA, port B4
    OPTION_REG = 0x0;
    WPUB = 0b00010000;
    
}

void startI2C()
{
    waitI2C();//Attente de lib�ration du SDA
    SSP1CON2=0b00000001;//Condition Start envoy�e
    while(SSP1CON2bits.SEN == 1);
}
void waitI2C()
{
    while ((SSP1STAT & 0x04) || (SSP1CON2 & 0x1F));//Test si transmission en cours / Test si I2C utilis� pour transmission, reception...
}
void stopI2C()
{
    waitI2C();//Attente de lib�ration du SDA
    SSP1CON2bits.PEN = 1;//Condition STOP envoy�e
    while(SSP1CON2bits.PEN == 1);
}
void sendI2C(uint8_t data)
{
    waitI2C();//Attente de lib�ration du SDA
    SSP1BUF = data;//Ecriture dans le registre SSP1BUF pour envoyer les donn�es sur SDA
    PIR1bits.SSP1IF = 0;
    while(PIR1bits.SSP1IF == 0);
}

uint8_t readI2C()
{
    uint8_t temp;
    waitI2C();//Attente de lib�ration du SDA
    SSP1CON2bits.RCEN = 1;//Conditon Recept activ�
    waitI2C();//Attente de lib�ration du SDA
    while(SSP1CON2bits.RCEN == 1);   
    temp = SSP1BUF;//R�cup�ration des donn�es re�ues par la ligne SDA
    
    return temp;//Renvoie des donn�es re�ues
}
void re_startI2C()
{
    waitI2C();//Attente de lib�ration du SDA
    SSP1CON2bits.RSEN = 1;//Condtion re-start envoy�e
    while(SSP1CON2bits.RSEN == 1);
}
void sendAckI2C()
{
    waitI2C();//Attente de lib�ration du SDA
    SSP1CON2bits.ACKDT = 0;//type ACK
    SSP1CON2bits.ACKEN = 1;//send ACK
}

void sendNoAckI2C()
{
    waitI2C();//Attente de lib�ration du SDA
    SSP1CON2bits.ACKDT = 1;//type No ACK
    SSP1CON2bits.ACKEN = 1;//send No ACK
}