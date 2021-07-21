#include <Arduino.h>
#include <Ultrasonic.h>
#include <Servo.h>

#define SERVO_PIN 5
#define TRIG_PIN 2
#define ECHO_PIN 3

unsigned long previousTime;
unsigned int servoSpeed = 10;

bool taskComplete = false;
int angle = 0;

Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN, 40000UL);
Servo servo;

void sendSerialData(int angle, Ultrasonic ultrasonic) {
    Serial.print(angle);
    Serial.print(",");
    Serial.println(ultrasonic.read());
}

void setup() {
    servo.attach(SERVO_PIN);
    servo.write(0);
    previousTime = millis();

    Serial.begin(9600);

    delay(1000);
}

void loop() {
    while (angle < 180) {
        if (millis() - previousTime > servoSpeed) {
            servo.write(angle);
            previousTime = millis();
            angle++;

            sendSerialData(angle, ultrasonic);
        }
    }

    while (angle > 0) {
        if (millis() - previousTime > servoSpeed) {
            servo.write(angle);
            previousTime = millis();
            angle--;

            sendSerialData(angle, ultrasonic);
        }
    }
}
