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

    if ((p.x > ButtonLED3.coordX) && (p.x < (ButtonLED3.coordX + ButtonLED3.width)) && (p.y > ButtonLED3.coordY) && (p.y <= (ButtonLED3.coordY + ButtonLED3.height)) && (millis() - touchInterval > 250))
    {

        if (!BtnState_LED3)
        {
            display.fillRect(ButtonLED3.coordX, ButtonLED3.coordY, ButtonLED3.width, ButtonLED3.height, TFT_GREEN);
            display.setCursor(ButtonLED3.coordX + 10, ButtonLED3.coordY + 10);
            display.print("LED3");
        }
        else
        {
            display.fillRect(ButtonLED3.coordX, ButtonLED3.coordY, ButtonLED3.width, ButtonLED3.height, TFT_BLUE);
            display.setCursor(ButtonLED3.coordX + 10, ButtonLED3.coordY + 10);
            display.print("LED3");
        }

        for (int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++)
            digitalWrite(ledPin[i], !digitalRead(ledPin[i]));
        BtnState_LED3 = !BtnState_LED3;
        touchInterval = millis();
    }

    if ((p.x > ButtonLED4.coordX) && (p.x < (ButtonLED4.coordX + ButtonLED4.width)) && (p.y > ButtonLED4.coordY) && (p.y <= (ButtonLED4.coordY + ButtonLED4.height)) && (millis() - touchInterval > 250))
    {
        Serial.println("Button touched!");

        if (!BtnState_LED4)
        {
            display.fillRect(ButtonLED4.coordX, ButtonLED4.coordY, ButtonLED4.width, ButtonLED4.height, TFT_GREEN);
            display.setCursor(ButtonLED4.coordX + 10, ButtonLED4.coordY + 10);
            display.print("LED4");
        }
        else
        {
            display.fillRect(ButtonLED4.coordX, ButtonLED4.coordY, ButtonLED4.width, ButtonLED4.height, TFT_BLUE);
            display.setCursor(ButtonLED4.coordX + 10, ButtonLED4.coordY + 10);
            display.print("LED4");
        }

        for (int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++)
            digitalWrite(ledPin[i], !digitalRead(ledPin[i]));
        BtnState_LED4 = !BtnState_LED4;
        touchInterval = millis();
    }

    if ((p.x > ButtonLED5.coordX) && (p.x < (ButtonLED5.coordX + ButtonLED5.width)) && (p.y > ButtonLED5.coordY) && (p.y <= (ButtonLED5.coordY + ButtonLED5.height)) && (millis() - touchInterval > 250))
    {
        Serial.println("Button touched!");

        if (!BtnState_LED5)
        {
            display.fillRect(ButtonLED5.coordX, ButtonLED5.coordY, ButtonLED5.width, ButtonLED5.height, TFT_GREEN);
            display.setCursor(ButtonLED5.coordX + 10, ButtonLED5.coordY + 10);
            display.print("LED5");
        }
        else
        {
            display.fillRect(ButtonLED5.coordX, ButtonLED5.coordY, ButtonLED5.width, ButtonLED5.height, TFT_BLUE);
            display.setCursor(ButtonLED5.coordX + 10, ButtonLED5.coordY + 10);
            display.print("LED5");
        }

        for (int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++)
            digitalWrite(ledPin[i], !digitalRead(ledPin[i]));
        BtnState_LED5 = !BtnState_LED5;
        touchInterval = millis();
    }

    if ((p.x > ButtonLED6.coordX) && (p.x < (ButtonLED6.coordX + ButtonLED6.width)) && (p.y > ButtonLED6.coordY) && (p.y <= (ButtonLED6.coordY + ButtonLED6.height)) && (millis() - touchInterval > 250))
    {
        Serial.println("Button touched!");

        if (!BtnState_LED6)
        {
            display.fillRect(ButtonLED6.coordX, ButtonLED6.coordY, ButtonLED6.width, ButtonLED6.height, TFT_GREEN);
            display.setCursor(ButtonLED6.coordX + 10, ButtonLED6.coordY + 10);
            display.print("LED6");
        }
        else
        {
            display.fillRect(ButtonLED6.coordX, ButtonLED6.coordY, ButtonLED6.width, ButtonLED6.height, TFT_BLUE);
            display.setCursor(ButtonLED6.coordX + 10, ButtonLED6.coordY + 10);
            display.print("LED6");
        }

        for (int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++)
            digitalWrite(ledPin[i], !digitalRead(ledPin[i]));
        BtnState_LED6 = !BtnState_LED6;
        touchInterval = millis();
    }

    if ((p.x > ButtonLED7.coordX) && (p.x < (ButtonLED7.coordX + ButtonLED7.width)) && (p.y > ButtonLED7.coordY) && (p.y <= (ButtonLED7.coordY + ButtonLED7.height)) && (millis() - touchInterval > 250))
    {
        Serial.println("Button touched!");

        if (!BtnState_LED7)
        {
            display.fillRect(ButtonLED7.coordX, ButtonLED7.coordY, ButtonLED7.width, ButtonLED7.height, TFT_GREEN);
            display.setCursor(ButtonLED7.coordX + 10, ButtonLED7.coordY + 10);
            display.print("LED7");
        }
        else
        {
            display.fillRect(ButtonLED7.coordX, ButtonLED7.coordY, ButtonLED7.width, ButtonLED7.height, TFT_BLUE);
            display.setCursor(ButtonLED7.coordX + 10, ButtonLED7.coordY + 10);
            display.print("LED7");
        }

        for (int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++)
            digitalWrite(ledPin[i], !digitalRead(ledPin[i]));
        BtnState_LED7 = !BtnState_LED7;
        touchInterval = millis();
    }

    if ((p.x > ButtonLED8.coordX) && (p.x < (ButtonLED8.coordX + ButtonLED8.width)) && (p.y > ButtonLED8.coordY) && (p.y <= (ButtonLED8.coordY + ButtonLED8.height)) && (millis() - touchInterval > 250))
    {
        Serial.println("Button touched!");

        if (!BtnState_LED8)
        {
            display.fillRect(ButtonLED8.coordX, ButtonLED8.coordY, ButtonLED8.width, ButtonLED8.height, TFT_GREEN);
            display.setCursor(ButtonLED8.coordX + 10, ButtonLED8.coordY + 10);
            display.print("LED8");
        }
        else
        {
            display.fillRect(ButtonLED8.coordX, ButtonLED8.coordY, ButtonLED8.width, ButtonLED8.height, TFT_BLUE);
            display.setCursor(ButtonLED8.coordX + 10, ButtonLED8.coordY + 10);
            display.print("LED8");
        }

        for (int i = 0; i < sizeof(ledPin) / sizeof(ledPin[0]); i++)
            digitalWrite(ledPin[i], !digitalRead(ledPin[i]));
        BtnState_LED8 = !BtnState_LED8;
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