/*
 * File:   ic.c
 * Author: Alex
 *
 * Created on July 5, 2018, 3:47 PM
 */


#include <xc.h>
#include <stdint.h>

void initI2C(void);
void startI2C();
void waitI2C();
void stopI2C();
void sendI2C(uint8_t);
uint8_t readI2C();
void re_startI2C();
void sendAckI2C();
void sendNoAckI2C();
uint8_t bitExtracted(uint8_t number, uint8_t k, uint8_t p);
uint8_t convertFromBcd(uint8_t byteBCD);
uint8_t FSM(uint8_t IN);
void initRTC();
void changeMin(uint8_t minute);
void changeHeure(uint8_t heure);
uint8_t readSec();
uint8_t readMin();
uint8_t readHr(); 
void incrMin();
void incrHeure();
void initI2C() {
    int i = 0;
    
    //Afin d'initialiser les périphériques I2C
    //Envoie de 9 coups d'horloge sur le pin SCL
    //Utile si PIC a redémarrer pendant une transmission ou reception et que le périphrique tient toujours la ligne SDA
    TRISB6 = 0;
    for (i = 0; i < 9; i++) {
        LATB6 = 1;
        LATB6 = 0;
    }
    
    //Configuration pin input
    TRISB6 = 1;//SCL PIN
    TRISB4 = 1;//SDA PIN

    //Mode digital port B
    ANSELB = 0x00;

    //Mise à l'état haut sur pin SCL et SDA
    LATB4 = 1;
    LATB6 = 1;
 
    //Registre I2C
    SSP1STAT = 0x80;//Standard Speed(100khz)
    SSP1CON1 = 0x28;//I2C master mode activé clock = Fosc/(4*(SSP1ADD+1)) //Activation port SDA et SCL
    SSP1CON2 = 0x00;
    SSP1ADD = 0x27;//Config clock SCL à 100kHz
    
    //Résistance pull-up SDA, port B4
    OPTION_REG = 0x0;
    WPUB = 0b00010000;
    
}

void startI2C()
{
    waitI2C();//Attente de libération du SDA
    SSP1CON2=0b00000001;//Condition Start envoyée
    while(SSP1CON2bits.SEN == 1);
}
void waitI2C()
{
    while ((SSP1STAT & 0x04) || (SSP1CON2 & 0x1F));//Test si transmission en cours / Test si I2C utilisé pour transmission, reception...
}
void stopI2C()
{
    waitI2C();//Attente de libération du SDA
    SSP1CON2bits.PEN = 1;//Condition STOP envoyée
    while(SSP1CON2bits.PEN == 1);
}
void sendI2C(uint8_t data)
{
    waitI2C();//Attente de libération du SDA
    SSP1BUF = data;//Ecriture dans le registre SSP1BUF pour envoyer les données sur SDA
    PIR1bits.SSP1IF = 0;
    while(PIR1bits.SSP1IF == 0);
}

uint8_t readI2C()
{
    uint8_t temp;
    waitI2C();//Attente de libération du SDA
    SSP1CON2bits.RCEN = 1;//Conditon Recept activé
    waitI2C();//Attente de libération du SDA
    while(SSP1CON2bits.RCEN == 1);   
    temp = SSP1BUF;//Récupération des données reçues par la ligne SDA
    
    return temp;//Renvoie des données reçues
}
void re_startI2C()
{
    waitI2C();//Attente de libération du SDA
    SSP1CON2bits.RSEN = 1;//Condtion re-start envoyée
    while(SSP1CON2bits.RSEN == 1);
}
void sendAckI2C()
{
    waitI2C();//Attente de libération du SDA
    SSP1CON2bits.ACKDT = 0;//type ACK
    SSP1CON2bits.ACKEN = 1;//send ACK
}

void sendNoAckI2C()
{
    waitI2C();//Attente de libération du SDA
    SSP1CON2bits.ACKDT = 1;//type No ACK
    SSP1CON2bits.ACKEN = 1;//send No ACK
}
uint8_t bitExtracted(uint8_t number, uint8_t k, uint8_t p) {
    return (((1 << k) - 1) & (number >> (p - 1)));
}

uint8_t convertFromBcd(uint8_t byteBCD) {
    uint8_t byteMSB = 0;
    uint8_t byteLSB = 0;
    byteMSB = (byteBCD & 0b11110000) >> 4;
    byteLSB = (byteBCD & 0b00001111);
    return ((byteMSB * 10) + byteLSB);
}

uint8_t FSM(uint8_t IN) {
    switch (IN) {
        case 0:
            return '0';
            break;

        case 1:
            return '1';
            break;

        case 2:
            return '2';
            break;

        case 3:
            return '3';
            break;

        case 4:
            return '4';
            break;

        case 5:
            return '5';
            break;

        case 6:
            return '6';
            break;

        case 7:
            return '7';
            break;

        case 8:
            return '8';
            break;

        case 9:
            return '9';
            break;
            // if IN doesn't match any of the above, do default.
        default:
            break;

    }
}
void initRTC() {
    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x00);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0b10000000);
    while (SSP1CON2bits.ACKSTAT == 1);
    stopI2C();

    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x01);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0b01001000);
    while (SSP1CON2bits.ACKSTAT == 1);
    stopI2C();

    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x02);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0b00010100);
    while (SSP1CON2bits.ACKSTAT == 1);
    stopI2C();
}

void changeMin(uint8_t minute)
{
    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x01);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(minute);
    while (SSP1CON2bits.ACKSTAT == 1);
    stopI2C();
}

void changeHeure(uint8_t heure)
{
    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x02);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(heure);
    while (SSP1CON2bits.ACKSTAT == 1);
    stopI2C();
}

uint8_t readSec() {
    uint8_t second = 0;
    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x00);
    while (SSP1CON2bits.ACKSTAT == 1);
    re_startI2C();
    sendI2C(0b11011111);
    while (SSP1CON2bits.ACKSTAT == 1);
    second = readI2C();
    sendNoAckI2C();
    stopI2C();
    return second;
}

uint8_t readMin() {
    uint8_t minute = 0;
    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x01);
    while (SSP1CON2bits.ACKSTAT == 1);
    re_startI2C();
    sendI2C(0b11011111);
    while (SSP1CON2bits.ACKSTAT == 1);
    minute = readI2C();
    sendNoAckI2C();
    stopI2C();
    return minute;
}

uint8_t readHr() {
    uint8_t heure = 0;
    startI2C();
    sendI2C(0b11011110);
    while (SSP1CON2bits.ACKSTAT == 1);
    sendI2C(0x02);
    while (SSP1CON2bits.ACKSTAT == 1);
    re_startI2C();
    sendI2C(0b11011111);
    while (SSP1CON2bits.ACKSTAT == 1);
    heure = readI2C();
    sendNoAckI2C();
    stopI2C();
    return heure;
}



void incrMin()
{
    uint8_t minute=0;
    uint8_t dizaineM=0;
    uint8_t uniteM=0;
    minute = readMin(); //lecture des minutes
    uniteM = bitExtracted(minute, 4, 1); //on extrait l'unité des minutes
    dizaineM = bitExtracted(minute, 3, 5); //on extrait les dizaines de minutes
    minute=0;
    uniteM=uniteM+1;
    if(uniteM>9)
    {
        uniteM=0;
        dizaineM=dizaineM+1;
    }
    if(dizaineM>6)
    {
        dizaineM=0;
        uniteM=0;
    }
    minute=minute+dizaineM;
    minute=minute<<4;
    minute=minute+uniteM;
    changeMin(minute);
}

void incrHeure()
{
    uint8_t heure=0;
    uint8_t dizaineH=0;
    uint8_t uniteH=0;
    heure = readHr(); //lecture des heures
    uniteH = bitExtracted(heure, 4, 1); //on extrait l'unité des heures
    dizaineH = bitExtracted(heure, 2, 5); //on extrait les dizaines d'heures
    heure=0;
    uniteH=uniteH+1;
    if(uniteH>9)
    {
        uniteH=0;
        dizaineH=dizaineH+1;
    }
    if(dizaineH>2 && uniteH==4)
    {
        dizaineH=0;
        uniteH=uniteH+1;
    }
    heure=heure+dizaineH;
    heure=heure<<4;
    heure=heure+uniteH;
    changeHeure(heure);
}