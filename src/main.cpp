#include "variables/variables.h"
#include "functions/functions.h"
#include "classes/classes.h"

void setup()
{
  servo.attach(servoPin);

  pinMode(proximitySensorPin, INPUT);
  for (int i = 0; i < 4; i++)
    pinMode(ledPin[i], OUTPUT);

  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(0, 0);
  tft.fillRect(Button1.coordX, Button1.coordY, Button1.width, Button1.height, TFT_BLUE);
  tft.drawRect(Button1.coordX, Button1.coordY, Button1.width, Button1.height, TFT_WHITE);
  tft.setCursor(Button1.coordX + 10, Button1.coordY + 10);
  tft.print("LED1");

  ledInterval = millis();
  servoInterval = millis();
  touchInterval = millis();
}

void loop()
{
  displayBTCheck();
  ledFunctionality(500);
  servoFunctionality(5000);
}