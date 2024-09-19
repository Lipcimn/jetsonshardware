#include <Arduino.h>
#include <Servo.h>
#include <TFT_eSPI.h>

#include "functions.h"
#include "pins/pins.h"
#include "classes/classes.h"

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
