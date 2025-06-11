const int buzzerPin = 9;
const int buttonPinL = 2;
const int buttonPinR = 7;

#include <Wire.h>
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte music[8] = {B00001, B00011, B00101, B01001, B01001, B01011, B11011, B11000};
byte speaker[8] = {B00001, B00011, B01111, B01111, B01111, B00011, B00001, B00000};
byte heart[8] = {B00000, B01010, B11111, B11111, B01110, B00100, B00000, B00000};
byte boundary[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};
byte doorL[8] = {B11111, B10001, B10001, B11111, B11111, B11101, B11111, B11111};
byte doorR[8] = {B11111, B10001, B10001, B11111, B11111, B10111, B11111, B11111};
byte man[8]    = {B01110, B10001, B11011, B00100, B11111, B00100, B01110, B10001};
byte key[8]    = {B01110, B10001, B10001, B01110, B00100, B00110, B00100, B00110};

int position = 8; // start position

bool leftPressedLast = false;
bool rightPressedLast = false;

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.clear();

  lcd.createChar(1, doorR);
  lcd.createChar(0, doorL);
  lcd.createChar(3, boundary);
  lcd.createChar(4, man);
  lcd.createChar(5, heart);
  lcd.createChar(6, key);

  pinMode(buttonPinL, INPUT_PULLUP);
  pinMode(buttonPinR, INPUT_PULLUP);

  drawMan(position, 4);
}

void loop() {
  bool leftPressed = !digitalRead(buttonPinL);
  bool rightPressed = !digitalRead(buttonPinR);

  if (leftPressed && !leftPressedLast && position > 1) {
    position--;
    drawMan(position, 4);
    buzz();
    delay(150);
  }

  if (rightPressed && !rightPressedLast && position < 15) {
    position++;
    drawMan(position, 4);
    buzz();
    delay(150);

  }

  // Win condition
  if (position == 1 || position == 15) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("YOU WIN!!!");
    victorySong();
    delay(1000);
    position = 8; // reset
    lcd.clear();
    drawMan(position, 4);
  }

  leftPressedLast = leftPressed;
  rightPressedLast = rightPressed;

}

void drawMan(int pos, int directionChar) {
  lcd.clear();

  // Draw boundary and base
  lcd.setCursor(1, 0);
  lcd.write(byte(0)); // doorL
  lcd.setCursor(15, 0);
  lcd.write(byte(1)); // doorR
  lcd.setCursor(1, 1);
  lcd.write(byte(3)); // boundary
  lcd.setCursor(15, 1);
  lcd.write(byte(3)); // boundary
  for (int i = 2; i < 15; i++) {
    lcd.setCursor(i, 1);
    lcd.print('=');
  }
  lcd.setCursor(0, 0);
  lcd.write(byte(5)); // heart
  lcd.setCursor(0, 1);
  lcd.write(byte(6)); // key

  lcd.setCursor(pos, 0);
  lcd.write(byte(directionChar));
}


void buzz() {
  tone(buzzerPin, 300, 50); // 1kHz tone for 100ms
}

void victorySong() {
  int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
  for (int i = 0; i < 8; i++) {
    tone(buzzerPin, melody[i], 150);
    delay(200);
  }
  noTone(buzzerPin);
}
