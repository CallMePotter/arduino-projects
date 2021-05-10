#include <Arduino.h>
#include <Servo.h>

Servo black;
Servo blue;

String serialData;

byte blackServo = 8;
byte blueServo = 9;

int x;
int y;

int parseDataX(String data) {
    data.remove(data.indexOf("Y"));
    data.remove(data.indexOf("X"), 1);

    return data.toInt();
}

int parseDataY(String data) {
    data.remove(0, data.indexOf("Y") + 1);

    return data.toInt();
}

void setup() {
    black.attach(blackServo);
    blue.attach(blueServo);

    black.write(90);
    blue.write(90);

    Serial.begin(9600);
    Serial.setTimeout(10);
}

void loop() {
}

void serialEvent() {
    serialData = Serial.readString();
    x = parseDataX(serialData);
    y = parseDataY(serialData);

    black.write(180 - x);
    blue.write(180 - y);
}
