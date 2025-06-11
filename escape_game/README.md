# 🕹️ Tamagotchi-Style LCD Game (Arduino Nano)

A simple LCD-based game inspired by retro handheld toys, built using an Arduino Nano. The player moves a character (the "man") toward the doors on either side of the screen. Reach a door and win the game — complete with sound and animation!

---

## 🎮 Features

- Character moves left or right using two buttons.
- Display uses a 16x2 I2C LCD screen.
- Buzzer plays a short sound on each move.
- Victory animation with melody when reaching either edge.
- Custom pixel sprites: man, doors, key, heart, boundary.

---

## 🛠️ Hardware Requirements

- **Arduino Nano** (or compatible)
- **I2C LCD Display** (16x2, typically at address `0x27`)
- **2 Push Buttons**
- **Piezo Buzzer**
- **Jumper Wires**
- **Breadboard**
- *(Optional)* Resistors if not using internal pull-ups

---

## 🔌 Wiring Guide

| Component      | Arduino Pin | Notes                        |
|----------------|-------------|------------------------------|
| LCD (I2C)      | A4 (SDA), A5 (SCL) | Use default I2C pins        |
| Left Button    | D2          | Uses `INPUT_PULLUP` mode     |
| Right Button   | D7          | Uses `INPUT_PULLUP` mode     |
| Buzzer         | D9          | Connect short leg to GND     |

> ⚠️ Buttons are configured using `INPUT_PULLUP`, so connect one side to GND. No external resistors are required.

---

## 🚀 Getting Started

1. Clone or download this repository.
2. Open the `.ino` file in the Arduino IDE.
3. Connect your components according to the wiring guide above.
4. Select **Arduino Nano** as your board and upload the code.
5. Start the game and press the buttons to move!

---

## 🧾 Game Rules

- Character starts in the center of the screen.
- Press **Left** or **Right** to move.
- Reach the left or right door to **win the game**.
- A victory message and sound play when you win.
- The game automatically resets for another round.