#ifndef MORSE_INPUT_H
#define MORSE_INPUT_H

#include "stm32f4xx_hal.h"

typedef enum {
    MORSE_NONE = 0,
    MORSE_DOT,
    MORSE_DASH,
    MORSE_SPACE,
    MORSE_ENTER
} MorseKey_t;

void MorseInput_Init(void);
MorseKey_t Morse_ReadInput(void);

#endif
