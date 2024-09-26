#include "classes/classes.h"
#include "functions/functions.h"
#include "variables/variables.h"

/**
 * Initializes the project setup()
 */
void projectSetup()
{
    Serial.begin(9600);

    servo.attach(servoPin);
    servo.write(0);

    pinMode(pirPin, INPUT);
    pinMode(buzzerPin, OUTPUT);

    for (int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++)
        pinMode(ledPin[i], OUTPUT);

    display.begin();
    display.setRotation(0);
    display.fillScreen(TFT_BLACK);
    display.setTextSize(1);
    display.setTextColor(TFT_WHITE);

    for (uint8_t i = 0; i < sizeof(Buttons) / sizeof(Buttons[0]); i++)
    {
        display.drawRect(Buttons[i].coordX, Buttons[i].coordY, Buttons[i].width, Buttons[i].height, TFT_WHITE);
        display.fillRect(Buttons[i].coordX, Buttons[i].coordY, Buttons[i].width, Buttons[i].height, TFT_BLUE);
        display.setCursor(Buttons[i].coordX + 10, Buttons[i].coordY + 10);
        display.print(Buttons[i].label);
    }

    if (!ts.begin(40))
    { // pass in 'sensitivity' coefficient
        Serial.println("Couldn't start FT6206 touchscreen controller");
        while (1)
            ;
    }

    Serial.println("Capacitive touchscreen started");

    ledInterval = millis();
    servoInterval = millis();
    touchInterval = millis();
    alarmInterval = millis();
}