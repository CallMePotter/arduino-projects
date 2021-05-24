#include <Arduino.h>
#include <Wire.h>
#include <Ultrasonic.h>

byte trigPin = 2;
byte echoPin = 3;

Ultrasonic ultrasonic(trigPin, echoPin);

void setup() {
    ultrasonic.setTimeout(40000UL);

    Serial.begin(9600);
}

void loop() {
    Serial.println(ultrasonic.read());

    delay(100);
}
