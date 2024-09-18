#include <Arduino.h>
#include <TFT_eSPI.h>
#include <stdint.h>
#include <Servo.h>

/* Pins Definition:
 * 1, 2, 3, 4 -> LEDs
 * 12 -> Proximity Sensor
 * 13 -> Servo
 */
const uint8_t led[4] = {10, 11, 12, 13};
const uint8_t proximitySensor = 14;
const uint8_t servoPin = 13;

Servo servo;

TFT_eSPI tft = TFT_eSPI();

// Variables
unsigned long ledInterval = millis();
unsigned long servoInterval = millis();

/**
 * Function that controls the LEDs
 * @param milliseconds: The time in milliseconds that the LEDs will be on
 */
void ledFunctionality(uint8_t milliseconds)
{
  if (millis() - ledInterval == milliseconds)
  {
    for (int i = 0; i < 4; i++)
      digitalWrite(led[i], HIGH);

    ledInterval = millis();
  }
  else
  {
    for (int i = 0; i < 4; i++)
      digitalWrite(led[i], LOW);
  }
}

/**
 * Function that controls the Servo
 * @param milliseconds: The time in milliseconds that the Servo will be on
 */
void servoFunctionality(uint8_t milliseconds)
{
  if (millis() - servoInterval == milliseconds)
  {
    servo.write(180);
    servoInterval = millis();
  }
  else
  {
    servo.write(0);
  }
}

void setup()
{
  servo.attach(servoPin);

  pinMode(proximitySensor, INPUT);
  for (int i = 0; i < 4; i++)
    pinMode(led[i], OUTPUT);

  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(0, 0);
}

void loop()
{
  ledFunctionality(500);
  servoFunctionality(5000);
}