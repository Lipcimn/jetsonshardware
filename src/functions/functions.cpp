#include "variables/variables.h"
#include "classes/classes.h"

/**
 * Function that controls the LEDs
 * @param milliseconds: The time in milliseconds that the LEDs will be on
 */
void ledFunctionality(uint16_t milliseconds)
{
    if (millis() - ledInterval == milliseconds)
    {
        for (int i = 0; i < 4; i++)
            digitalWrite(ledPin[i], !digitalRead(ledPin[i]));

        ledInterval = millis();
    }
}

/**
 * Function that controls the Servo
 * @param milliseconds: The time in milliseconds that the Servo will be on
 */
void servoFunctionality(uint16_t milliseconds)
{
    if (millis() - servoInterval == milliseconds)
    {
        Serial.println(servo.read());
        servo.write((servo.read() == -1) ? 180 : 0);
        servoInterval = millis();
    }
}

/**
 * Checks if the display has been touched and updates the display and other functionalities.
 */
void displayBTCheck()
{

    if (!ts.touched())
        return;

    TS_Point p = ts.getPoint();

    Serial.print("X = ");
    Serial.print(p.x);
    Serial.print("\tY = ");
    Serial.print(p.y);
    Serial.print(" -> ");

    p.x = map(p.x, 0, 240, 240, 0);
    p.y = map(p.y, 0, 320, 320, 0);

    Serial.print("(");
    Serial.print(p.x);
    Serial.print(", ");
    Serial.println(p.y);

    if ((p.x > Button1.coordX) && (p.x < (Button1.coordX + Button1.width)) && (p.y > Button1.coordY) && (p.y <= (Button1.coordY + Button1.height)) && (millis() - touchInterval > 500))
    {
        Serial.println("Button touched!");
        display.fillRect(Button1.coordX, Button1.coordY, Button1.width, Button1.height, TFT_GREEN);
        display.setCursor(Button1.coordX + 10, Button1.coordY + 10);
        digitalWrite(ledPin[0], HIGH);
    }
    else
    {
        display.fillRect(Button1.coordX, Button1.coordY, Button1.width, Button1.height, TFT_BLUE);
        display.setCursor(Button1.coordX + 10, Button1.coordY + 10);
        digitalWrite(ledPin[0], LOW);
    }
}
