#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

String incoming = "";

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Waiting for");
  lcd.setCursor(0,1);
  lcd.print("weather...");
}

void loop() {
  // Read serial input if available
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\r') {
      // Newline or carriage return marks end of message
      displayOnLCD(incoming);
      incoming = "";
    } else {
      incoming += c;
    }
  }
}

void displayOnLCD(String msg) {
  lcd.clear();
  // If message is longer than 16 characters, split between lines
  if (msg.length() <= 16) {
    lcd.setCursor(0, 0);
    lcd.print(msg);
  } else {
    lcd.setCursor(0, 0);
    lcd.print(msg.substring(0, 16));
    lcd.setCursor(0, 1);
    lcd.print(msg.substring(16, 32));
  }
}