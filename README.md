# Environmental Monitoring System

## Project Overview
This repository contains the source code for an embedded system designed to monitor environmental parameters in real-time. The system utilizes a microcontroller to interface with multiple sensors, acquiring data regarding ambient temperature, relative humidity, and illuminance. Data is processed and visualized via an SH1106 OLED interface.

## System Specifications

### Functional Capabilities
* **Temperature Monitoring:** Real-time acquisition of ambient temperature (°C).
* **Humidity Sensing:** Measurement of relative humidity percentage (%).
* **Illuminance Detection:** High-precision light intensity measurement in Lux (lx).
* **Data Visualization:** Immediate display of sensor readings via an OLED interface with a 2-second refresh rate.

### Hardware Configuration
The firmware is designed for Arduino-compatible microcontrollers (e.g., Uno, Nano, ESP32) and integrates the following components:

* **DHT11:** Digital temperature and humidity sensor.
* **BH1750:** Digital Ambient Light Sensor (I2C interface).
* **SH1106 OLED Display:** 128x64 pixel graphic display (I2C interface).

## Pin Configuration
The system utilizes the I2C communication protocol for the display and light sensor, and a digital pin for the DHT11.

| Component | Interface | Microcontroller Pin |
| :--- | :--- | :--- |
| **DHT11 Data** | Digital IO | Pin 2 |
| **SH1106 OLED** | I2C SDA | SDA (A4 on Uno/Nano) |
| **SH1106 OLED** | I2C SCL | SCL (A5 on Uno/Nano) |
| **BH1750** | I2C SDA | SDA (A4 on Uno/Nano) |
| **BH1750** | I2C SCL | SCL (A5 on Uno/Nano) |

## Software Dependencies
The following libraries are required for compilation. These must be installed via the Arduino Library Manager:

1.  `Adafruit GFX Library` (Core graphics library)
2.  `Adafruit SH110X` (Display driver)
3.  `BH1750` (Christopher Laws)
4.  `DHT sensor library` (Adafruit)

## Deployment Instructions
1.  Clone this repository to your local machine.
2.  Ensure all hardware connections match the Pin Configuration table.
3.  Install the required dependencies via the Arduino IDE or PlatformIO.
4.  Compile and upload the firmware (`EnvironmentMonitor.ino`) to the target microcontroller.
