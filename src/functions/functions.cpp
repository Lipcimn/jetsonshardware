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

    if ((p.x > ButtonLED1.coordX) && (p.x < (ButtonLED1.coordX + ButtonLED1.width)) && (p.y > ButtonLED1.coordY) && (p.y <= (ButtonLED1.coordY + ButtonLED1.height)) && (millis() - touchInterval > 250))
    {
        Serial.println("Button touched!");

        if (!BtnState_LED1)
        {
            display.fillRect(ButtonLED1.coordX, ButtonLED1.coordY, ButtonLED1.width, ButtonLED1.height, TFT_GREEN);
            display.setCursor(ButtonLED1.coordX + 10, ButtonLED1.coordY + 10);
            display.print("LED1");
        }
        else
        {
            display.fillRect(ButtonLED1.coordX, ButtonLED1.coordY, ButtonLED1.width, ButtonLED1.height, TFT_BLUE);
            display.setCursor(ButtonLED1.coordX + 10, ButtonLED1.coordY + 10);
            display.print("LED1");
        }

        for (int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++)
            digitalWrite(ledPin[i], !digitalRead(ledPin[i]));
        BtnState_LED1 = !BtnState_LED1;
        touchInterval = millis();
    }

    if ((p.x > ButtonLED2.coordX) && (p.x < (ButtonLED2.coordX + ButtonLED2.width)) && (p.y > ButtonLED2.coordY) && (p.y <= (ButtonLED2.coordY + ButtonLED2.height)) && (millis() - touchInterval > 250))
    {
        Serial.println("Button touched!");

        if (!BtnState_LED2)
        {
            display.fillRect(ButtonLED2.coordX, ButtonLED2.coordY, ButtonLED2.width, ButtonLED2.height, TFT_GREEN);
            display.setCursor(ButtonLED2.coordX + 10, ButtonLED2.coordY + 10);
            display.print("LED2");
        }
        else
        {
            display.fillRect(ButtonLED2.coordX, ButtonLED2.coordY, ButtonLED2.width, ButtonLED2.height, TFT_BLUE);
            display.setCursor(ButtonLED2.coordX + 10, ButtonLED2.coordY + 10);
            display.print("LED2");
        }

        for (int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++)
            digitalWrite(ledPin[i], !digitalRead(ledPin[i]));
        BtnState_LED2 = !BtnState_LED2;
        touchInterval = millis();
    }

    if ((p.x > ButtonSERVO.coordX) && (p.x < (ButtonSERVO.coordX + ButtonSERVO.width)) && (p.y > ButtonSERVO.coordY) && (p.y <= (ButtonSERVO.coordY + ButtonSERVO.height)) && (millis() - touchInterval > 250))
    {
        Serial.println("Button touched!");

        if (!BtnState_SERVO)
        {
            display.fillRect(ButtonSERVO.coordX, ButtonSERVO.coordY, ButtonSERVO.width, ButtonSERVO.height, TFT_GREEN);
            display.setCursor(ButtonSERVO.coordX + 10, ButtonSERVO.coordY + 10);
            display.print("SERVO");
        }
        else
        {
            display.fillRect(ButtonSERVO.coordX, ButtonSERVO.coordY, ButtonSERVO.width, ButtonSERVO.height, TFT_BLUE);
            display.setCursor(ButtonSERVO.coordX + 10, ButtonSERVO.coordY + 10);
            display.print("SERVO");
        }

        servo.write((servo.read() == -1) ? 180 : 0);
        BtnState_SERVO = !BtnState_SERVO;
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