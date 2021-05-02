#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <Ultrasonic.h>

byte ultraPower = A0;
byte ultraGround = A3;

byte rs = 12;
byte en = 11;

byte d4 = 6;
byte d5 = 5;
byte d6 = 4;
byte d7 = 3;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Ultrasonic ultrasonic(A1, A2);


void setup() {
    pinMode(ultraPower, OUTPUT);
    pinMode(ultraGround, OUTPUT);

    digitalWrite(ultraPower, HIGH);
    digitalWrite(ultraGround, LOW);

    lcd.begin(16, 2);
    ultrasonic.setTimeout(40000UL);
}

void loop() {
    lcd.clear();

    lcd.print("Distance: ");
    lcd.print(ultrasonic.read());
    lcd.print(" cm");

    delay(500);
}
