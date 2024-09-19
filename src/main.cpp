#include <Arduino.h>
#include "pins/pins.h"
#include "functions/functions.h"
#include "classes/classes.h"

#include <TFT_eSPI.h>

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