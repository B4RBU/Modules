#include <xc.h>
#include <stdint.h>
#include "header.h"

void initI2C();
void startI2C();
void waitI2C();
void stopI2C();
void sendI2C(uint8_t);
uint8_t readI2C();
void re_startI2C();
void sendAckI2C();
void sendNoAckI2C();

