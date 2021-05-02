#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 5
#define DHTTYPE DHT11

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
    Serial.begin(9600);
    dht.begin();
    delayMS = 250;
}

void loop() {
    delay(delayMS);

    sensors_event_t event;

    dht.temperature().getEvent(&event);

    if (isnan(event.temperature)) {
        Serial.println(F("Error reading temperature!"));
    } else {
        Serial.print(event.temperature);
    }

    dht.humidity().getEvent(&event);

    if (isnan(event.relative_humidity)) {
        Serial.println(F("Error reading humidity!"));
    } else {
        Serial.print(F(" , "));
        Serial.println(event.relative_humidity);
    }
}
