#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <BH1750.h>
#include "DHT.h"

// ==== DHT11 Sensor Settings ====
#define DHTPIN 2        
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ==== Light Sensor (BH1750) ====
BH1750 lightMeter;

// ==== OLED Display (SH1106, I2C addr 0x3C) ====
Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1);

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize sensors
  dht.begin();
  lightMeter.begin();

  // Initialize OLED
  if (!display.begin(0x3C, true)) {
    Serial.println(F("SH1106 not found!"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.println(F("System ready!"));
  display.display();
  delay(2000); // Show startup text for 2s
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float lux = lightMeter.readLightLevel();

  // If sensor read failed
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT!"));
    return;
  }

  // Serial Monitor output
  Serial.print(F("Temp: ")); Serial.print(t); Serial.print(" °C  ");
  Serial.print(F("Hum: ")); Serial.print(h); Serial.print(" %  ");
  Serial.print(F("Lux: ")); Serial.println(lux);

  // ==== OLED update ====
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("Environment Monitor"));
  display.println(F("-------------------"));
  display.print(F("Temp: ")); display.print(t); display.println(F(" C"));
  display.print(F("Hum : ")); display.print(h); display.println(F(" %"));
  display.print(F("Lux : ")); display.print(lux); display.println(F(" lx"));
  display.display();

  delay(2000); // Update every 2s
}

