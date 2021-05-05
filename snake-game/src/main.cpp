#include <Arduino.h>

byte xPin = A5;
byte yPin = A4;
byte bPin = A3;

int xVal;
int yVal;
int bVal;

void setup() {
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);
    pinMode(bPin, INPUT);
    digitalWrite(bPin, HIGH);

    Serial.begin(9600);
}

void loop() {
    xVal = analogRead(xPin);
    yVal = analogRead(yPin);
    bVal = digitalRead(bPin);

    Serial.print(xVal);
    Serial.print(" ");
    Serial.print(yVal);
    Serial.print(" ");
    Serial.println(bVal);
    delay(25);
}
