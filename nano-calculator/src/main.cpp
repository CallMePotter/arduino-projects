#include <Arduino.h>
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <math.h>

char key;
String first;
String second;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte rowPins[ROWS] = {8, 9, 10, 11};
byte colPins[COLS] = {A5, A4, A3, A2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal lcd(12, 2, 4, 5, 6, 7);

void getElements() {
        lcd.clear();
        lcd.print("First: ");
        while (key != '#') {
            key = keypad.getKey();
            if (key && key != '#') {
                first += key;
                lcd.clear();
                lcd.print("First: ");
                lcd.print(first.toInt());
            }
        }

        lcd.clear();
        lcd.print("Second: ");
        key = ' ';
        while (key != '#') {
            key = keypad.getKey();
            if (key && key != '#') {
                second += key;
                lcd.clear();
                lcd.print("Second: ");
                lcd.print(second.toInt());
            }
        }
        lcd.clear();
}

void setup() {
    lcd.begin(16, 2);
    lcd.print("Add(A) Sub(B)");
    lcd.setCursor(0, 2);
    lcd.print("Mul(C) Div(D)");
}

void loop() {
    key = keypad.getKey();

    if (key == 'A') {
        getElements();
        lcd.print("Answer: ");
        lcd.print(first.toFloat() + second.toFloat());
        first = "";
        second = "";
    } else if (key == 'B') {
        getElements();
        lcd.print("Answer: ");
        lcd.print(first.toFloat() - second.toFloat());
        first = "";
        second = "";
    } else if (key == 'C') {
        getElements();
        lcd.print("Answer: ");
        lcd.print(first.toFloat() * second.toFloat());
        first = "";
        second = "";
    } else if (key == 'D') {
        getElements();
        lcd.print("Answer: ");
        lcd.print(first.toFloat() / second.toFloat());
        first = "";
        second = "";
    }
}
