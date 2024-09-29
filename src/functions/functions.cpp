#include "variables/variables.h"
#include "classes/classes.h"

/**
 * Function that controls the LEDs
 * @param milliseconds: The time in milliseconds that the LEDs will be on
 */
void ledFunctionality(uint16_t milliseconds)
{
    if (millis() - ledInterval != milliseconds)
        return;

    for (int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++)
        digitalWrite(ledPin[i], !digitalRead(ledPin[i]));

    ledInterval = millis();
}

/**
 * Function that controls the Servo
 * @param milliseconds: The time in milliseconds that the Servo will be on
 */
void servoFunctionality(uint16_t milliseconds)
{
    if (millis() - servoInterval != milliseconds)
        return;

    servo.write((servo.read() == -1) ? 180 : 0);

    servoInterval = millis();
}

/**
 * Checks if the display has been touched and updates the display and other functionalities.
 */
void Touch()
{
    if (!ts.touched())
    {
        // Reset last touched button if the user is not pressing the display so that the user can press the buttons again.
        lastTouchedButton = DisplayBT(0, 0, 0, 0, "NULL");
        // Reset noButtonClick if the user is not pressing the display anymore.
        noButtonClick = false;
        return;
    }

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

    // Map each button and check if it was touched
    for (uint8_t i = 0; i < sizeof(Buttons) / sizeof(Buttons[0]); i++)
    {
        if ((p.x > Buttons[i].coordX) && (p.x < (Buttons[i].coordX + Buttons[i].width)) && (p.y > Buttons[i].coordY) && (p.y <= (Buttons[i].coordY + Buttons[i].height)) && (millis() - touchInterval > 250) && !(lastTouchedButton == Buttons[i]) && !noButtonClick)
        {
            Serial.println("Button touched!");

            // Update last touched button.
            lastTouchedButton = DisplayBT(Buttons[i]);

            if (strstr(Buttons[i].label, "LED") != NULL)
                digitalWrite(ledPin[i], !digitalRead(ledPin[i]));

            if (strstr(Buttons[i].label, "SERVO") != NULL)
                servo.write((servo.read() == -1) ? 180 : 0);

            Buttons[i].state = !Buttons[i].state;
            touchInterval = millis();

            display.fillRect(Buttons[i].coordX, Buttons[i].coordY, Buttons[i].width, Buttons[i].height, (Buttons[i].state) ? TFT_GREEN : TFT_BLUE);
            display.setCursor(Buttons[i].coordX + 10, Buttons[i].coordY + 10);
            display.print(Buttons[i].label);
        }
    }

    if ((p.x > lastTouchedButton.coordX) && (p.x < (lastTouchedButton.coordX + lastTouchedButton.width)) && (p.y > lastTouchedButton.coordY) && (p.y <= (lastTouchedButton.coordY + lastTouchedButton.height)) && !(lastTouchedButton == DisplayBT(0, 0, 0, 0, "NULL")))
    {
        noButtonClick = false;
        return;
    }

    noButtonClick = true;
}

void Alarm(uint16_t milliseconds)
{
    digitalWrite(buzzerPin, (alarmActive) ? HIGH : LOW);

    if (alarmActive && millis() - alarmInterval >= milliseconds) // Checks for alarm variable state
        alarmActive = 0;

    if (digitalRead(pirPin) == LOW) // Return if PIR Sensor is not activated
        return;

    if (!alarmActive)
        alarmActive = 1, alarmInterval = millis();
}