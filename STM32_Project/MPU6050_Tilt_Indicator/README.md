🎯 STM32 Tilt Detector — Real-Time Motion Sensing with LCD & UART
✨ Project Overview

This project is a hands-on exploration of embedded systems, sensors, and real-time data visualization.
Using an STM32 microcontroller and an MPU6050 accelerometer, the system continuously monitors device orientation. The results are:

Displayed on a 16x2 I²C LCD, and

Transmitted over UART for logging/debugging.

It’s a compact yet powerful project that brings together I²C communication, UART debugging, and sensor fusion basics — an excellent step toward mastering embedded development.

🛠️ Hardware Components

STM32F103C8T6 (Blue Pill) – the heart of the project

MPU6050 – 3-axis accelerometer + gyroscope sensor

16x2 LCD with I²C backpack (PCF8574) – to display tilt direction

USB-to-UART module – for debugging/logging tilt data

Breadboard, jumper wires, power via USB or external 5V

🔌 Circuit Connections
Component	STM32 Pin	Notes
MPU6050 SDA	PB7	I²C1 SDA (shared with LCD)
MPU6050 SCL	PB6	I²C1 SCL (shared with LCD)
LCD SDA	PB7	Shared I²C line
LCD SCL	PB6	Shared I²C line
LCD VCC	5V	Power
LCD GND	GND	Ground
MPU6050 VCC	3.3V	⚠️ Do not connect to 5V
MPU6050 GND	GND	Ground
UART TX	PA9	Connect to USB-UART RX
UART RX	PA10	Connect to USB-UART TX

💡 Tip: Add 4.7k–10k pull-up resistors on SDA & SCL lines for stable I²C communication.

🧭 Working Principle

The MPU6050 sensor measures acceleration in X, Y, and Z axes. Based on the X and Y values:

Tilt Right → AccelX > +Threshold

Tilt Left → AccelX < -Threshold

Tilt Forward → AccelY > +Threshold

Tilt Backward → AccelY < -Threshold

Stable → within threshold range

The detected tilt is:
✅ Displayed on the LCD in human-readable form
✅ Logged over UART for debugging

Example LCD output:

Device is tilted
   to Left Side


Example UART log:

Tilt: Left | AccelX=-2500, AccelY=120

⚙️ Software Structure

lcd.c/h → I²C LCD driver

mpu6050.c/h → MPU6050 sensor driver

tilt.c/h → Core logic for tilt detection

main.c → Initializes peripherals and runs detection loop

Development environment:

STM32CubeIDE / Keil uVision

HAL libraries for I²C, UART, GPIO

▶️ Getting Started

Clone this repository:

git clone https://github.com/username/Embedded-Projects.git
cd Embedded-Projects/STM32_Tilt_Detector


Open in STM32CubeIDE

Build & flash to STM32 board

Connect USB-UART & open Serial Monitor @ 115200 baud

Tilt the board and watch results appear on both LCD and UART 🎉

📸 Demo

LCD:

Device is tilted
   to Right Side


UART:

Tilt: Right | AccelX=2800
