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
void touch()
{
    if (!display.getTouch(&x, &y))
    {
        // Reset last touched button if the user is not pressing the display so that the user can press the buttons again.
        lastTouchedButton = DisplayBT(0, 0, 0, 0, "NULL");
        // Reset noButtonClick if the user is not pressing the display anymore.
        noButtonClick = false;
        return;
    }

    Serial.print("X = ");
    Serial.print(x);
    Serial.print("\tY = ");
    Serial.print(y);
    Serial.print(" -> ");

    /* x = map(p.x, 0, 240, 240, 0);
    y = map(p.y, 0, 320, 320, 0); */

    // Map each button and check if it was touched
    for (uint8_t i = 0; i < sizeof(Buttons) / sizeof(Buttons[0]); i++)
    {
        if ((x > Buttons[i].coordX) && (x < (Buttons[i].coordX + Buttons[i].width)) && (y > Buttons[i].coordY) && (y <= (Buttons[i].coordY + Buttons[i].height)) && (millis() - touchInterval > 250) && !(lastTouchedButton == Buttons[i]) && !noButtonClick)
        {
            Serial.println("Button touched!");

            // Update last touched button.
            lastTouchedButton = DisplayBT(Buttons[i]);

            if (strstr(Buttons[i].label, "LED") != NULL)
                digitalWrite(ledPin[i], !digitalRead(ledPin[i]));

            if (strstr(Buttons[i].label, "SERVO") != NULL)
                servo.write((servo.read() == -1) ? 180 : 0);

            if (strstr(Buttons[i].label, "ALARM") != NULL)
                alarmToogle = !alarmToogle;

            Buttons[i].state = !Buttons[i].state;
            touchInterval = millis();

            display.fillRect(Buttons[i].coordX, Buttons[i].coordY, Buttons[i].width, Buttons[i].height, (Buttons[i].state) ? TFT_GREEN : TFT_BLUE);
            display.setCursor(Buttons[i].coordX + 10, Buttons[i].coordY + 10);
            display.print(Buttons[i].label);
        }
    }

    if ((x > lastTouchedButton.coordX) && (x < (lastTouchedButton.coordX + lastTouchedButton.width)) && (y > lastTouchedButton.coordY) && (y <= (lastTouchedButton.coordY + lastTouchedButton.height)) && !(lastTouchedButton == DisplayBT(0, 0, 0, 0, "NULL")))
    {
        noButtonClick = false;
        return;
    }

    noButtonClick = true;
}

void alarm(uint16_t milliseconds)
{
    if (!alarmToogle) {
        noTone(buzzerPin);
        return;
    }

    alarmActive ? tone(buzzerPin, 1000) : noTone(buzzerPin);

    if (alarmActive && millis() - alarmInterval >= milliseconds) // Checks for alarm variable state
        alarmActive = 0;

    if (digitalRead(pirPin) == LOW) // Return if PIR Sensor is not activated
        return;

    if (!alarmActive)
        alarmActive = 1, alarmInterval = millis();
}

/**
 * Checks the DHT11 humidity and temperature values
 */
void temperatureAndHumidity(uint16_t milliseconds)
{
    if (millis() - dhtInterval <= milliseconds)
        return;

    temperature = dht.readTemperature();
    humidity = dht.readHumidity();

    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidade: ");
    Serial.print(humidity);
    Serial.println(" %");

    /*
     * Checks if current last values differs from updated temperature and humidity values
     * This prevents having to update the values on the display all the time
     */
    if (currentHumidity != humidity)
    {
        display.setCursor(humidLabel.coordX, humidLabel.coordY);
        display.fillRect(humidLabel.coordX, humidLabel.coordY, humidLabel.width, humidLabel.height, humidLabel.color);

        display.print("Umidade: ");
        display.print(humidity);
        display.print("%");

        currentHumidity = humidity;
    }

    if (currentTemperature != temperature)
    {
        display.setCursor(tempLabel.coordX, tempLabel.coordY);
        display.fillRect(tempLabel.coordX, tempLabel.coordY, tempLabel.width, tempLabel.height, tempLabel.color);

        display.print("Temperatura: ");
        display.print(temperature);
        display.print(" C");

        currentTemperature = temperature;
    }

    dhtInterval = millis();
}