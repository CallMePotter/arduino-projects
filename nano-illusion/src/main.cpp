#include <Arduino.h>
#include <Stepper.h>

int stepsPerRevolution = 2048;
int speed = 10;
int step = 1;

byte button = 12;
Stepper stepper(stepsPerRevolution, 7, 5, 6, 4);

byte buttonState;
byte buttonOldState;
bool stepperState = true;

void setup() {
    Serial.begin(9600);

    pinMode(button, INPUT);
    digitalWrite(button, HIGH);

    stepper.setSpeed(speed);
}

void loop() {
    buttonState = digitalRead(button);

    if (buttonState == 1 && buttonOldState == 0) {
        step = -step;
    }

    stepper.step(step);

    buttonOldState = buttonState;
}
