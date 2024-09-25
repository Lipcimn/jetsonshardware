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

    display.drawRect(Button1.coordX, Button1.coordY, Button1.width, Button1.height, TFT_WHITE);
    display.fillRect(Button1.coordX, Button1.coordY, Button1.width, Button1.height, TFT_BLUE);
    display.setCursor(Button1.coordX + 10, Button1.coordY + 10);
    display.print("LED1");

    display.drawRect(Button2.coordX, Button2.coordY, Button2.width, Button2.height, TFT_WHITE);
    display.fillRect(Button2.coordX, Button2.coordY, Button2.width, Button2.height, TFT_BLUE);
    display.setCursor(Button2.coordX + 10, Button2.coordY + 10);
    display.print("SERVO");

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