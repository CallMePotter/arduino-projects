#include <Arduino.h>

byte buttonPin = 2;
byte buttonVal;

void setup() {
    pinMode(buttonPin, INPUT);
    digitalWrite(buttonPin, HIGH);

    Serial.begin(9600);
}

void loop() {
    buttonVal = digitalRead(buttonPin);

    Serial.println(buttonVal);
    delay(100);
}
