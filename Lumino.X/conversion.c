#include "header.h"
#include "mcc_generated_files/mcc.h"

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
