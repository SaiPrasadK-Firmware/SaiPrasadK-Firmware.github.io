#include "morse.h"
#include <string.h>

typedef struct {
    char symbol;
    const char *code;
} MorseCode;

MorseCode morseTable[] = {
    {'A', ".-"},   {'B', "-..."},
    {'C', "-.-."}, {'D', "-.."},
    {'E', "."},    {'F', "..-."},
    {'G', "--."},  {'H', "...."},
    {'I', ".."},   {'J', ".---"},
    {'K', "-.-"},  {'L', ".-.."},
    {'M', "--"},   {'N', "-."},
    {'O', "---"},  {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."},  {'T', "-"},
    {'U', "..-"},  {'V', "...-"},
    {'W', ".--"},  {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
    {' ', " "}
};

char decodeMorse(char *code) {
    for (int i = 0; i < sizeof(morseTable)/sizeof(MorseCode); i++) {
        if (strcmp(code, morseTable[i].code) == 0) {
            return morseTable[i].symbol;
        }
    }
    return '?';
}
