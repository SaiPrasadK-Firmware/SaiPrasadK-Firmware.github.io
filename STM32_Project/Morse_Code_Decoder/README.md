# ⚡ Morse Code Decoder – STM32F401RE

![Morse Code](https://img.shields.io/badge/STM32-Embedded-blue)
![Language](https://img.shields.io/badge/Language-C-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

This is one of my first **hands-on STM32 projects** where I challenged myself to build a **Morse Code Decoder**.  
I started with the basics of GPIO input (button), added feedback with an LED, and then scaled it up to display text on an LCD and store messages in EEPROM.  

I did this project mainly to **learn embedded firmware design and peripheral interfacing** on STM32F401RE.

---

## 🚀 What I Built

- A system that lets me **input Morse code** by pressing a button.  
- Each dot (`.`) and dash (`-`) is captured in real time.  
- The decoded text is shown on a **16x2 I2C LCD**.  
- The final message can be **saved into an external EEPROM (24C04)**.  
- An **onboard LED** gives instant feedback for every press.  

This small project gave me confidence in combining multiple peripherals (GPIO, I2C, EEPROM, LCD) into one working application.

---

## 💡 Why I Did It

- To practice **real-time signal processing** (detecting button press length).  
- To learn how to **interface an LCD and EEPROM over I2C**.  
- To explore how to **store and retrieve messages** in external memory.  
- To make something **interactive and fun** beyond just blinking an LED.  

---

## 🛠️ Hardware Connections

### STM32F401RE (Nucleo-64) Pin Mapping

| Peripheral       | STM32 Pin | Connected To         |
|------------------|-----------|----------------------|
| **LCD I2C SDA**  | PB7       | LCD SDA              |
| **LCD I2C SCL**  | PB6       | LCD SCL              |
| **EEPROM SDA**   | PB7       | Shared with LCD SDA  |
| **EEPROM SCL**   | PB6       | Shared with LCD SCL  |
| **Push Button**  | PA0       | External button input|
| **LED (Feedback)**| PA5      | Onboard LD2 LED      |
| **Power**        | 3.3V / GND| Common rails         |

> Both LCD and EEPROM work on I²C, so they share the same **SDA/SCL lines**.

---

## 📦 Tools & Setup

- **STM32CubeIDE** for writing and flashing the code  
- **HAL drivers** for I²C, GPIO, EEPROM  
- **GitHub** for version control  

---

## ⚡ How It Works

1. When I press the button:  
   - Short press = Dot (`.`)  
   - Long press = Dash (`-`)  
   - Pause = Space (between letters)  

2. Every dot/dash sequence is stored in a buffer.  
3. The buffer is compared against a Morse code lookup table.  
4. Decoded characters appear live on the **LCD screen**.  
5. Pressing **Enter (custom condition)** stores the whole message into EEPROM.  
6. The onboard LED blinks to confirm each input.  

---

## 📖 Example

Inputting the word **HELLO**:  

| Morse Input            | Decoded Output |
|------------------------|----------------|
| `.... . .-.. .-.. ---` | HELLO          |

---

## 🎯 What I Learned

- How to **differentiate short vs long button presses** using timers.  
- How to **drive a 16x2 I²C LCD** from STM32.  
- How to use **EEPROM (24C04) for non-volatile storage**.  
- Structuring code with **HAL drivers** and keeping it modular.  
- Debugging with LED feedback before moving to LCD/EERPOM.  

This felt like building a mini embedded system from scratch — hardware + firmware + debugging.

---

## 🔗 Repo & Resources

- Full project repo: [Morse Code Decoder – Source Code](https://github.com/YOUR_USERNAME/Morse_Code_Decoder)  
- [STM32CubeF4 HAL Documentation](https://www.st.com/en/embedded-software/stm32cubef4.html)  

---

## 📄 License
MIT License
