#include <Arduino.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

byte redPin = A6;
byte bluePin = A7;
byte greenPin = 4;

byte buzz = 11;

byte b1 = A0;
byte b2 = A1;
byte b3 = A2;
byte b4 = A3;
byte b5 = A4;
byte b6 = A5;
byte b7 = 7;
byte b8 = 6;
byte b9 = 3;
byte b10 = 2;
byte b11 = 10;
byte b12 = 5;

byte v1;
byte v2;
byte v3;
byte v4;
byte v5;
byte v6;
byte v7;
byte v8;
byte v9;
byte v10;
byte v11;
byte v12;

void setup() {
    pinMode(buzz, OUTPUT);

    pinMode(b1, INPUT);
    digitalWrite(b1, HIGH);

    pinMode(b2, INPUT);
    digitalWrite(b2, HIGH);

    pinMode(b3, INPUT);
    digitalWrite(b3, HIGH);

    pinMode(b4, INPUT);
    digitalWrite(b4, HIGH);

    pinMode(b5, INPUT);
    digitalWrite(b5, HIGH);

    pinMode(b6, INPUT);
    digitalWrite(b6, HIGH);

    pinMode(b7, INPUT);
    digitalWrite(b7, HIGH);

    pinMode(b8, INPUT);
    digitalWrite(b8, HIGH);

    pinMode(b9, INPUT);
    digitalWrite(b9, HIGH);

    pinMode(b10, INPUT);
    digitalWrite(b10, HIGH);

    pinMode(b11, INPUT);
    digitalWrite(b11, HIGH);

    pinMode(b12, INPUT);
    digitalWrite(b12, HIGH);

    pinMode(bluePin, OUTPUT);
    digitalWrite(bluePin, HIGH);

    Serial.begin(9600);
}

void loop() {
    v1 = digitalRead(b1);
    v2 = digitalRead(b2);
    v3 = digitalRead(b3);
    v4 = digitalRead(b4);
    v5 = digitalRead(b5);
    v6 = digitalRead(b6);
    v7 = digitalRead(b7);
    v8 = digitalRead(b8);
    v9 = digitalRead(b9);
    v10 = digitalRead(b10);
    v11 = digitalRead(b11);
    v12 = digitalRead(b12);

    if (v1 == 0) {
        digitalWrite(buzz, HIGH);
        delayMicroseconds(NOTE_B6);
        digitalWrite(buzz, LOW);
    }

    else if (v2 == 0) {
        digitalWrite(buzz, HIGH);
        delayMicroseconds(NOTE_AS6);
        digitalWrite(buzz, LOW);
    }

    else if (v3 == 0) {
        digitalWrite(buzz, HIGH);
        delayMicroseconds(NOTE_A6);
        digitalWrite(buzz, LOW);
    }

    else if (v4 == 0) {
        digitalWrite(buzz, HIGH);
        delayMicroseconds(NOTE_GS6);
        digitalWrite(buzz, LOW);
    }

    else if (v5 == 0) {
        digitalWrite(buzz, HIGH);
        delayMicroseconds(NOTE_G6);
        digitalWrite(buzz, LOW);
    }

    else if (v6 == 0) {
        digitalWrite(buzz, HIGH);
        delayMicroseconds(NOTE_FS6);
        digitalWrite(buzz, LOW);
    }

    else if (v7 == 0) {
        digitalWrite(buzz, HIGH);
        delayMicroseconds(NOTE_F6);
        digitalWrite(buzz, LOW);
    }

    else if (v8 == 0) {
        digitalWrite(buzz, HIGH);
        delayMicroseconds(NOTE_E6);
        digitalWrite(buzz, LOW);
    }

    else if (v9 == 0) {
        digitalWrite(buzz, HIGH);
        delayMicroseconds(NOTE_DS6);
        digitalWrite(buzz, LOW);
    }

    else if (v10 == 0) {
        digitalWrite(buzz, HIGH);
        delayMicroseconds(NOTE_D6);
        digitalWrite(buzz, LOW);
    }

    else if (v11 == 0) {
        digitalWrite(buzz, HIGH);
        delayMicroseconds(NOTE_CS6);
        digitalWrite(buzz, LOW);
    }

    else if (v12 == 0) {
        digitalWrite(buzz, HIGH);
        delayMicroseconds(NOTE_C6);
        digitalWrite(buzz, LOW);
    }
}
