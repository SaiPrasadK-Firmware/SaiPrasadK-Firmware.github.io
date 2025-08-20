# 💡 LED Blink – STM32F401RE

![STM32](https://img.shields.io/badge/Board-STM32F401RE-blue)
![HAL](https://img.shields.io/badge/Framework-STM32CubeHAL-green)
![Language](https://img.shields.io/badge/Language-C-orange)

The simplest and most essential project for getting started with **STM32 development**.  
This program toggles the **onboard LED (LD2 at PA5)** on the STM32F401RE Nucleo board every 500 ms.

---

## 🚀 Features
- Blinks the onboard **LD2 LED** using GPIO.
- Configures system clock and GPIO using STM32 HAL.
- Provides a base template for all future STM32 projects.

---

## 🛠️ Hardware
| Component | Details |
|-----------|---------|
| MCU       | STM32F401RE (Nucleo-64 board) |
| LED       | Onboard LD2 (connected to PA5) |
| Power     | USB (5V) |

---

## 📦 Software & Tools
- **STM32CubeIDE** (or Keil, PlatformIO)
- **STM32Cube HAL Drivers**
- GitHub for version control

---

## 📐 Pinout / Connection
- **PA5 → Onboard LD2 LED**
- No external hardware required.

---

## 📜 Code Overview

```c
int main(void)
{
  HAL_Init();                 // Initialize HAL library
  SystemClock_Config();       // Configure system clock
  MX_GPIO_Init();             // Init GPIO

  while (1)
  {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // Toggle PA5 (LD2 LED)
    HAL_Delay(500);                        // 500 ms delay
  }
}
