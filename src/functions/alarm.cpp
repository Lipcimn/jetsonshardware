#include "variables/variables.h"
#include "classes/classes.h"

void alarm(uint16_t milliseconds)
{
    // Verifica o estado do botão do alarme | Check ALARM button state
    if (!Buttons[7].state)
    {
        noTone(buzzerPin);
        return;
    }

    alarmActive ? tone(buzzerPin, 1000) : noTone(buzzerPin);

    if (alarmActive && millis() - alarmInterval >= milliseconds) // Verifica o estado da variável do alarme | Checks for alarm variable state
        alarmActive = 0;

    if (digitalRead(pirPin) == LOW) // Retorna se o sensor PIR não estiver ativado | Return if PIR Sensor is not activated
        return;

    if (!alarmActive)
        alarmActive = 1, alarmInterval = millis();
}