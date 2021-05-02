#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTPIN A0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

byte tempGround = A2;
byte tempPower = A1;

byte rs = 12;
byte en = 11;

byte d4 = 6;
byte d5 = 5;
byte d6 = 4;
byte d7 = 3;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    pinMode(tempGround, OUTPUT);
    pinMode(tempPower, OUTPUT);

    digitalWrite(tempGround, LOW);
    digitalWrite(tempPower, HIGH);

    lcd.begin(16, 2);
    dht.begin();

    lcd.print("Temperature and");
    lcd.setCursor(0, 1);
    lcd.print("humidity sensor");
}

void loop() {
    delay(2000);

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float hic = dht.computeHeatIndex(t, h, false);

    lcd.clear();

    lcd.print("T: ");
    lcd.print(t);
    lcd.print(" H: ");
    lcd.print(h);
    lcd.setCursor(0, 1);
    lcd.print("I: ");
    lcd.print(hic);

    Serial.println(h);
}
