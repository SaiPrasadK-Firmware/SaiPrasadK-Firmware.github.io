STM32 Tilt Detector — Real-Time Motion Sensing with LCD & UART
Project Overview
This project demonstrates a real-time tilt detection system using an STM32F103C8T6 microcontroller and an MPU6050 accelerometer/gyroscope sensor. The system detects device orientation (Left, Right, Forward, Backward, or Stable) and displays the results on a 16x2 I²C LCD while logging data over UART for debugging. It’s a hands-on exploration of embedded systems, I²C communication, and sensor fusion, ideal for learning embedded development and IoT applications.

Features

Detects tilt direction (Left, Right, Forward, Backward, or Stable)
Displays tilt status on a 16x2 LCD via I²C
Logs live accelerometer data over UART
Integrates multiple peripherals (I²C, UART, GPIO) for a cohesive system
Potential applications: gesture-based controls, motion-sensitive devices, self-balancing robots


Hardware Components

STM32F103C8T6 (Blue Pill): Core microcontroller
MPU6050: 3-axis accelerometer + gyroscope sensor
16x2 LCD with I²C backpack (PCF8574): Displays tilt direction
USB-to-UART module: For debugging and logging
Breadboard and jumper wires
Power: USB or external 5V supply


Circuit Connections



Component
STM32 Pin
Notes



MPU6050 SDA
PB7
I²C1 SDA (shared with LCD)


MPU6050 SCL
PB6
I²C1 SCL (shared with LCD)


LCD SDA
PB7
Shared I²C line


LCD SCL
PB6
Shared I²C line


LCD VCC
5V
Power


LCD GND
GND
Ground


MPU6050 VCC
3.3V
⚠️ Do not connect to 5V


MPU6050 GND
GND
Ground


UART TX
PA9
Connect to USB-UART RX


UART RX
PA10
Connect to USB-UART TX


Tip: Use 4.7k–10kΩ pull-up resistors on SDA and SCL lines for stable I²C communication.

Working Principle
The MPU6050 measures acceleration along X, Y, and Z axes. Tilt is determined based on X and Y values with predefined thresholds and a deadband for stability:

Tilt Right: AccelX > +Threshold
Tilt Left: AccelX < -Threshold
Forward: AccelY > +Threshold
Backward: AccelY < -Threshold
Stable: Within threshold range

Outputs:

LCD: Displays human-readable tilt status (e.g., "Device is tilted to Left Side")
UART: Logs tilt direction and raw accelerometer data (e.g., "Tilt: Left | AccelX=-2500, AccelY=120")


Software Structure

lcd.c/h: Driver for I²C LCD (PCF8574)
mpu6050.c/h: Driver for MPU6050 sensor
tilt.c/h: Core logic for tilt detection and processing
main.c: Initializes peripherals and runs the detection loop

Development Environment:

IDE: STM32CubeIDE or Keil uVision
Libraries: STM32 HAL for I²C, UART, and GPIO


Getting Started

Clone the Repository:
git clone https:  https://github.com/SaiPrasadK-Firmware/SaiPrasadK-Firmware.github.io/edit/main/STM32_Project/MPU6050_Tilt_Indicator


Set Up Hardware:

Connect components as per the circuit connections table.
Ensure pull-up resistors are added to I²C lines (SDA, SCL).
Power the STM32 via USB or a 5V supply.


Build and Flash:

Open the project in STM32CubeIDE or Keil uVision.
Build the project.
Flash the code to the STM32F103C8T6 using an ST-Link or similar programmer.


Monitor Output:

Connect the USB to stlink
Open a serial monitor (e.g., PuTTY, Tera Term) at 115200 baud.
Tilt the board to see real-time results on the LCD and UART.



Example Outputs:

LCD:Device is tilted
   to Right Side


UART:Tilt: Right | AccelX=2800, AccelY=120




