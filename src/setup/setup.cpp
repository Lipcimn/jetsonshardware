#include "classes/classes.h"
#include "functions/functions.h"
#include "variables/variables.h"

/**
 * Initializes the project setup()
 */
void projectSetup()
{
    servo.attach(servoPin);

    pinMode(proximitySensorPin, INPUT);
    for (int i = 0; i < 4; i++)
        pinMode(ledPin[i], OUTPUT);

    display.begin();
    display.setRotation(1);
    display.fillScreen(TFT_BLACK);
    display.setTextSize(1);
    display.setTextColor(TFT_WHITE);
    display.setCursor(0, 0);
    display.drawRect(Button1.coordX, Button1.coordY, Button1.width, Button1.height, TFT_WHITE);
    display.fillRect(Button1.coordX, Button1.coordY, Button1.width, Button1.height, TFT_BLUE);
    display.setCursor(Button1.coordX + 10, Button1.coordY + 10);
    display.print("LED1");

    ledInterval = millis();
    servoInterval = millis();
    touchInterval = millis();
}