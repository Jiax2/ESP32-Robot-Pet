# ESP32-Robot-Pet
A small robotic pet using an ESP32, a round TFT display, a servo motor and a button.

## Hardware

| Component | Model / Notes |
|---|---|
| Microcontroller | ESP32 Dev Module with expansion board |
| Display | 1.28" round TFT, GC9A01 driver, SPI, 240x240 |
| Servo | SG90 9g micro servo |
| Button | Built-in BOOT button on ESP32 |
| Power | USB-C to ESP32, servo powered from 5V/VIN |

## Pinout

### Display: GC9A01 SPI TFT

| Display Pin | ESP32 GPIO | Purpose |
|---|---:|---|
| VCC | 3V3 | Display power |
| GND | GND | Ground |
| SCL | GPIO18 | SPI clock |
| SDA | GPIO23 | SPI MOSI / data |
| DC | GPIO2 | Data/command select |
| CS | GPIO5 | Chip select |
| RST | GPIO4 | Display reset |

### Servo: SG90

| Servo Wire | ESP32 Pin | Purpose |
|---|---|---|
| Brown | GND | Ground |
| Red | VIN / 5V | Servo power |
| Orange | GPIO13 | PWM control signal |

### Button

| Button | ESP32 GPIO | Purpose |
|---|---:|---|
| BOOT button | GPIO0 | Start / stop servo test |

