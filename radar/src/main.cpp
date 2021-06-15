#include <Arduino.h>
#include <Ultrasonic.h>
#include <Servo.h>

#define SERVO_PIN 5
#define TRIG_PIN 2
#define ECHO_PIN 3

unsigned long previousTime;
unsigned int servoSpeed = 10;

bool taskComplete = false;
int count = 0;

Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN, 40000UL);
Servo servo;

void sendSerialData(Ultrasonic ultrasonic, int count) {
    Serial.print(ultrasonic.read());
    Serial.print(" ");
    Serial.println(count);
}

void setup() {
    servo.attach(SERVO_PIN);
    servo.write(0);
    previousTime = millis();

    Serial.begin(9600);

    delay(1000);
}

void loop() {
    while (count < 180) {
        if (millis() - previousTime > servoSpeed) {
            servo.write(count);
            previousTime = millis();
            count++;

            sendSerialData(ultrasonic, count);
        }
    }

    while (count > 0) {
        if (millis() - previousTime > servoSpeed) {
            servo.write(count);
            previousTime = millis();
            count--;

            sendSerialData(ultrasonic, count);
        }
    }
}
