#include <Arduino.h>
#include <Ultrasonic.h>
#include <Servo.h>

#define SERVO_PIN 5
#define TRIG_PIN 2
#define ECHO_PIN 3

unsigned long previousTime;
bool taskComplete = false;
int count = 0;
int servoSpeed = 10;

Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN, 40000UL);
Servo servo;

void setup() {
    servo.attach(SERVO_PIN);
    previousTime = millis();

    Serial.begin(9600);
}

void loop() {
    while (count < 180) {
        if (millis() - previousTime > servoSpeed) {
            servo.write(count);
            previousTime = millis();
            count++;

            Serial.println(ultrasonic.read());
        }
    }

    while (count > 0) {
        if (millis() - previousTime > servoSpeed) {
            servo.write(count);
            previousTime = millis();
            count--;

            Serial.println(ultrasonic.read());
        }
    }
}
