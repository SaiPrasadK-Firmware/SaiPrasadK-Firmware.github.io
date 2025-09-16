# STM32F4 Tilt Detection System  

This repository contains code and documentation for a **tilt detection system** based on the **STM32F401RE** microcontroller and the **MPU6050** accelerometer/gyroscope.  
The project demonstrates **real-time orientation sensing**, **LCD display**, **UART debugging**, and **LED status indication** — useful for **learning and prototyping embedded sensor applications**.  

---

## 🛠️ Hardware Used  
- **STM32F401RE Nucleo board**  
- **MPU6050 Accelerometer + Gyroscope (I2C)**  
- **16x2 LCD with I2C backpack**  
- **Red / Green LEDs**  
- **UART connection for debugging (tested with TeraTerm)**  

---

## ✨ Features  
- Detects tilt direction:  
  - **Left** / **Right** / **Forward** / **Backward**  
- LCD shows current tilt status in **plain language**  
- UART prints **live accelerometer/gyroscope values** for debugging  
- Red/Green LEDs indicate **stable vs. tilted orientation**  

---

## 📐 Schematic  
- Both **MPU6050** and **LCD** share the STM32’s I2C bus.  
- Red/Green LEDs are connected to **GPIO pins** with limiting resistors.  
- UART TX pin connected to **USB–UART adapter**.  
- *(See schematic image in `/Docs` folder for wiring details.)*  

---

## ⚙️ How It Works  
1. **I2C Communication**  
   - MPU6050 sensor and LCD are connected via the STM32’s I2C bus.  

2. **Sensor Fusion**  
   - Raw accelerometer and gyroscope data are processed using a **deadband/threshold approach** to detect tilt.  

3. **Display & Indication**  
   - Detected tilt direction → shown on **LCD**  
   - **LEDs** indicate stable or tilted state  
   - **UART** sends real-time sensor values for monitoring/debugging  

---

## 🚀 Getting Started  

### 🔌 Hardware Connections  
- Connect **MPU6050** and **LCD** to STM32 **I2C pins**  
- Connect **Red/Green LEDs** to GPIO pins (with resistors)  
- Connect **UART TX** to USB–UART adapter  

### 💻 Software Setup  
- Open the project in **STM32CubeIDE**  
- Build and flash firmware to the **STM32F401RE board**  
- Open serial terminal (**115200 baud**) to view sensor output  

---

## 📚 Key Learnings  
- Working with **multiple I2C peripherals** on a single bus  
- Handling raw **sensor data** and applying thresholds  
- Integrating **LCD, UART, and GPIO drivers** in one project  

---
---

## 📂 Repository Structure  
/Src → Source code (main.c, sensor drivers, etc.)
/Inc → Header files
/Docs → Reference material, schematics
/Project → STM32CubeIDE project files
README.md → Project documentation
