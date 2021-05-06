#include <Arduino.h>
#include <Wire.h>
#include <Ultrasonic.h>

byte trigPin1 = 2;
byte echoPin1 = 3;

byte trigPin2 = 4;
byte echoPin2 = 5;

Ultrasonic ultrasonic1(trigPin1, echoPin1);
Ultrasonic ultrasonic2(trigPin2, echoPin2);

void setup() {
    ultrasonic1.setTimeout(40000UL);
    ultrasonic2.setTimeout(40000UL);

    Serial.begin(9600);
}

void loop() {
    Serial.print(ultrasonic1.read());
    Serial.print(" ");
    Serial.println(ultrasonic2.read());

    delay(250);
}
