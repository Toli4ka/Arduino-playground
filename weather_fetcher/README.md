# Arduino Weather LCD Display

This project displays current weather information on an LCD screen connected to an Arduino Uno (or Nano). Weather data is fetched from OpenWeatherMap using a Python script running on your computer, then sent to the Arduino over USB serial.

## Features

- Shows live weather (temperature and description) for your city
- Uses an LCD display (16x2, I2C or standard)

## Hardware Required

- Arduino Uno or Nano
- 16x2 LCD (with I2C backpack recommended)
- USB cable for Arduino
- Computer running Python

## How It Works

1. Arduino displays a default message on the LCD.
2. Python script fetches live weather data from OpenWeatherMap.
3. Script sends the weather info to Arduino over USB serial.
4. Arduino updates the LCD with the received weather.