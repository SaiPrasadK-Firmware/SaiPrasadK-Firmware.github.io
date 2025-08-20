#include "morse_input.h"

#define BUTTON_PORT GPIOC
#define BUTTON_PIN  GPIO_PIN_13

static uint32_t lastPressTime = 0;
static uint8_t pressCount = 0;

void MorseInput_Init(void)
{

    lastPressTime = 0;
    pressCount = 0;
}

MorseKey_t Morse_ReadInput(void)
{
    // Check button press (active low)
    if (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN) == GPIO_PIN_RESET)
    {
        HAL_Delay(50); // debounce
        if (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN) == GPIO_PIN_RESET)
        {
            lastPressTime = HAL_GetTick();
            pressCount++;
            while (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN) == GPIO_PIN_RESET); // wait release
        }
    }

    // If some presses happened and idle > 800ms
    if (pressCount > 0 && (HAL_GetTick() - lastPressTime) > 800)
    {
        MorseKey_t result = MORSE_NONE;

        if (pressCount == 1) result = MORSE_DOT;
        else if (pressCount == 2) result = MORSE_DASH;
        else if (pressCount == 3) result = MORSE_SPACE;
        else if (pressCount >= 4) result = MORSE_ENTER;

        pressCount = 0; // reset
        return result;
    }

    return MORSE_NONE; // nothing yet
}
