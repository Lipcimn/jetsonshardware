#include "variables/variables.h"
#include "classes/classes.h"

void alarm(uint16_t milliseconds)
{
    // Check ALARM button state
    if (!Buttons[7].state)
    {
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