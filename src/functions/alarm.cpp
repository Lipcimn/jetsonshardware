#include "variables/variables.h"
#include "classes/classes.h"

void alarm(uint16_t milliseconds)
{
    // Verifica o estado do botão do alarme | Check ALARM button state
    if (!Buttons[7].state)
    {
        ledcWrite(buzzerChannel, 0);
        return;
    }

    alarmActive ? ledcWrite(buzzerChannel, 128) : ledcWrite(buzzerChannel, 0);

    if (alarmActive && millis() - alarmInterval >= milliseconds) // Verifica o estado da variável do alarme e se o tempo do alarme acabou | Checks for alarm variable state and if the alarm time has ended
        alarmActive = 0;

    if (digitalRead(pirPin) == LOW) // Retorna se o sensor PIR não estiver ativado | Return if PIR Sensor is not activated
        return;

    if (!alarmActive)
        alarmActive = 1, alarmInterval = millis();
}