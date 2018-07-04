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