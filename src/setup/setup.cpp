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

    display.drawRect(ButtonLED1.coordX, ButtonLED1.coordY, ButtonLED1.width, ButtonLED1.height, TFT_WHITE);
    display.fillRect(ButtonLED1.coordX, ButtonLED1.coordY, ButtonLED1.width, ButtonLED1.height, TFT_BLUE);
    display.setCursor(ButtonLED1.coordX + 10, ButtonLED1.coordY + 10);
    display.print("LED1");

    display.drawRect(ButtonLED2.coordX, ButtonLED2.coordY, ButtonLED2.width, ButtonLED2.height, TFT_WHITE);
    display.fillRect(ButtonLED2.coordX, ButtonLED2.coordY, ButtonLED2.width, ButtonLED2.height, TFT_BLUE);
    display.setCursor(ButtonLED2.coordX + 10, ButtonLED2.coordY + 10);
    display.print("LED2");

    display.drawRect(ButtonLED3.coordX, ButtonLED3.coordY, ButtonLED3.width, ButtonLED3.height, TFT_WHITE);
    display.fillRect(ButtonLED3.coordX, ButtonLED3.coordY, ButtonLED3.width, ButtonLED3.height, TFT_BLUE);
    display.setCursor(ButtonLED3.coordX + 10, ButtonLED3.coordY + 10);
    display.print("LED3");

    display.drawRect(ButtonLED4.coordX, ButtonLED4.coordY, ButtonLED4.width, ButtonLED4.height, TFT_WHITE);
    display.fillRect(ButtonLED4.coordX, ButtonLED4.coordY, ButtonLED4.width, ButtonLED4.height, TFT_BLUE);
    display.setCursor(ButtonLED4.coordX + 10, ButtonLED4.coordY + 10);
    display.print("LED4");

    display.drawRect(ButtonLED5.coordX, ButtonLED5.coordY, ButtonLED5.width, ButtonLED5.height, TFT_WHITE);
    display.fillRect(ButtonLED5.coordX, ButtonLED5.coordY, ButtonLED5.width, ButtonLED5.height, TFT_BLUE);
    display.setCursor(ButtonLED5.coordX + 10, ButtonLED5.coordY + 10);
    display.print("LED5");

    display.drawRect(ButtonLED6.coordX, ButtonLED6.coordY, ButtonLED6.width, ButtonLED6.height, TFT_WHITE);
    display.fillRect(ButtonLED6.coordX, ButtonLED6.coordY, ButtonLED6.width, ButtonLED6.height, TFT_BLUE);
    display.setCursor(ButtonLED6.coordX + 10, ButtonLED6.coordY + 10);
    display.print("LED6");

    display.drawRect(ButtonLED7.coordX, ButtonLED7.coordY, ButtonLED7.width, ButtonLED7.height, TFT_WHITE);
    display.fillRect(ButtonLED7.coordX, ButtonLED7.coordY, ButtonLED7.width, ButtonLED7.height, TFT_BLUE);
    display.setCursor(ButtonLED7.coordX + 10, ButtonLED7.coordY + 10);
    display.print("LED7");

    display.drawRect(ButtonLED8.coordX, ButtonLED8.coordY, ButtonLED8.width, ButtonLED8.height, TFT_WHITE);
    display.fillRect(ButtonLED8.coordX, ButtonLED8.coordY, ButtonLED8.width, ButtonLED8.height, TFT_BLUE);
    display.setCursor(ButtonLED8.coordX + 10, ButtonLED8.coordY + 10);
    display.print("LED8");

    display.drawRect(ButtonSERVO.coordX, ButtonSERVO.coordY, ButtonSERVO.width, ButtonSERVO.height, TFT_WHITE);
    display.fillRect(ButtonSERVO.coordX, ButtonSERVO.coordY, ButtonSERVO.width, ButtonSERVO.height, TFT_BLUE);
    display.setCursor(ButtonSERVO.coordX + 10, ButtonSERVO.coordY + 10);
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