# ⚡ Morse Code Decoder – STM32F401RE

![Morse Code](https://img.shields.io/badge/STM32-Embedded-blue)
![Language](https://img.shields.io/badge/Language-C%2B%2B-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

A real-time **Morse Code Decoder** built using **STM32F401RE**, with live LCD display, EEPROM storage, and push-button input. Perfect for learning embedded systems, firmware development, and real-time signal processing.

---

## 🚀 Features

- Input Morse code using onboard button
- Real-time decoding and display on **16x2 I2C LCD**
- Stores decoded messages in **EEPROM 24C04**
- Onboard LED blinks for feedback of input
- Simple firmware architecture for STM32F4 series
- Expandable for more projects or advanced Morse code features

---

## 💻 Hardware Used

| Component | Model / Specs |
|-----------|---------------|
| MCU       | STM32F401RE (Nucleo) |
| Display   | 16x2 I2C LCD |
| Storage   | EEPROM 24C04 |
| Input     | Push Button |
| Feedback  | Onboard LED |

---

## 📦 Software & Tools

- **STM32CubeIDE / Keil / PlatformIO**
- **HAL libraries** for STM32
- C/C++ for firmware
- GitHub for version control

---

## ⚡ Quick Demo

### Input Method:
- **Short Press (.)**: Dot
- **Long Press (-)**: Dash
- **Pause**: Space between letters
- **Enter**: Store message to EEPROM

### Example:

| Morse Input       | Decoded Output |
|-----------------|----------------|
| .... . .-.. .-.. --- | HELLO |

LED blinks with every input to give feedback.

---

## 🛠️ Installation / Flashing

1. Clone this repository:
```bash
git clone https://github.com/YOUR_USERNAME/Morse_Code_Decoder.git
