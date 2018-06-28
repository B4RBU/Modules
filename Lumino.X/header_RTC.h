#include <xc.h>
#include "header.h"

void initRTC();
void changeMin(uint8_t minute);
void changeHeure(uint8_t heure);
uint8_t readSec();
uint8_t readMin();
uint8_t readHr(); 
void incrMin();
void incrHeure();