#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/interrupt_manager.h"


#define BUF_LEN 64

#define LED1 RC5
#define LED2 RA2
#define LED3 RA1
#define LED4 RA5
#define _XTAL_FREQ 16000000//Freq Fosc pour __delay_ms(x))

void init(void);
void system_init(void);
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

void Partiel_Reset();
void Set_Features();
void Set_Mode();
void Reboot();
void Turn_On();
void delay_ms(int msec);
void init_B();
int Verif_Erreur(char * buf, unsigned int size);
void lecture();
char ReturnReg();

void WriteOnBt(unsigned int);
void Scan(); 
void StopScan();
void connexion();
void remote();