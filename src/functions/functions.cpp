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

    if ((p.x > Button1.coordX) && (p.x < (Button1.coordX + Button1.width)) && (p.y > Button1.coordY) && (p.y <= (Button1.coordY + Button1.height)) && (millis() - touchInterval > 250))
    {
        Serial.println("Button touched!");

        if (!ButtonLED)
        {
            display.fillRect(Button1.coordX, Button1.coordY, Button1.width, Button1.height, TFT_GREEN);
            display.setCursor(Button1.coordX + 10, Button1.coordY + 10);
            display.print("LED1");
        }
        else
        {
            display.fillRect(Button1.coordX, Button1.coordY, Button1.width, Button1.height, TFT_BLUE);
            display.setCursor(Button1.coordX + 10, Button1.coordY + 10);
            display.print("LED1");
        }

        for (int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++)
            digitalWrite(ledPin[i], !digitalRead(ledPin[i]));
        ButtonLED = !ButtonLED;
        touchInterval = millis();
    }

    if ((p.x > Button2.coordX) && (p.x < (Button2.coordX + Button2.width)) && (p.y > Button2.coordY) && (p.y <= (Button2.coordY + Button2.height)) && (millis() - touchInterval > 250))
    {
        Serial.println("Button touched!");

        if (!ButtonSERVO)
        {
            display.fillRect(Button2.coordX, Button2.coordY, Button2.width, Button2.height, TFT_GREEN);
            display.setCursor(Button2.coordX + 10, Button2.coordY + 10);
            display.print("SERVO");
        }
        else
        {
            display.fillRect(Button2.coordX, Button2.coordY, Button2.width, Button2.height, TFT_BLUE);
            display.setCursor(Button2.coordX + 10, Button2.coordY + 10);
            display.print("SERVO");
        }

        servo.write((servo.read() == -1) ? 180 : 0);
        ButtonSERVO = !ButtonSERVO;
        touchInterval = millis();
    }
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