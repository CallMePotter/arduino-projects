#include <Arduino.h>
#include <Stepper.h>
#include <Ultrasonic.h>

byte b1 = A0;
byte b2 = A1;
byte b3 = A5;

bool direction = true;
bool rotation = true;
bool manual = true;

int stepsPerRevolution = 2048;

byte echoPin1 = 2;
byte trigPin1 = 3;

byte echoPin2 = 6;
byte trigPin2 = 5;

Stepper stepper = Stepper(stepsPerRevolution, 11, 9, 10, 8);

Ultrasonic ultrasonic1(trigPin1, echoPin1, 40000UL);
Ultrasonic ultrasonic2(trigPin2, echoPin2, 40000UL);

void getUltrasonicData(Ultrasonic ultrasonic1, Ultrasonic ultrasonic2, bool rotation) {
    Serial.print(ultrasonic1.read());
    Serial.print(" ");
    Serial.print(ultrasonic2.read());
    Serial.print(" ");
    Serial.println(rotation);
}

void setup() {
    pinMode(b1, INPUT_PULLUP);
    pinMode(b2, INPUT_PULLUP);
    pinMode(b3, INPUT_PULLUP);
    stepper.setSpeed(5);

    Serial.begin(9600);
}

void loop() {
    if (digitalRead(b1) == 0) {
        direction = true;
    }

    if (digitalRead(b2) == 0) {
        direction = false;
    }

    if (digitalRead(b3) == 0) {
        manual = false;
    }

    if (!manual) {
        for (int i = 0; i < stepsPerRevolution / 2; i++) {
            stepper.step(1);
            rotation = true;

            getUltrasonicData(ultrasonic1, ultrasonic2, rotation);
        }

        for (int i = 0; i < stepsPerRevolution / 2; i++) {
            stepper.step(-1);
            rotation = false;

            getUltrasonicData(ultrasonic1, ultrasonic2, rotation);
        }
    }

    if (direction && manual) stepper.step(1);
    if (!direction && manual) stepper.step(-1);
}
