#include "variables/variables.h"
#include "classes/classes.h"

/**
 * Checa se o display foi pressionado, atualiza o display e outras funcionalidades | Checks if the display has been touched and updates the display and other functionalities.
 */
void touch()
{
    if (!display.getTouch(&x, &y))
    {
        // Reseta o último botão pressionado se o usuário não está pressionado o display para que o mesmo consiga pressionar algum botão novamente | Reset last touched button if the user is not pressing the display so that the user can press the buttons again.
        lastTouchedButton = DisplayBT(0, 0, 0, 0, "NULL");
        // Reseta noButtonse o usuário não estiver mais pressionado o display  | Reset noButtonClick if the user is not pressing the display anymore.
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

    // Mapeia cada botão e verifica se o mesmo foi pressionado | Map each button and check if it was touched
    for (uint8_t i = 0; i < sizeof(Buttons) / sizeof(Buttons[0]); i++)
    {
        if ((x > Buttons[i].coordX) && (x < (Buttons[i].coordX + Buttons[i].width)) && (y > Buttons[i].coordY) && (y <= (Buttons[i].coordY + Buttons[i].height)) && (millis() - touchInterval > 250) && !(lastTouchedButton == Buttons[i]) && !noButtonClick)
        {
            Serial.println("Button touched!");

            // Atualiza qual foi o último botão pressionado | Update last touched button.
            lastTouchedButton = DisplayBT(Buttons[i]);

            if (strstr(Buttons[i].label, "COZNH") != NULL || strstr(Buttons[i].label, "JANTA") != NULL || strstr(Buttons[i].label, "ESCRI") != NULL || strstr(Buttons[i].label, "SALA") != NULL || strstr(Buttons[i].label, "BANHO") != NULL || strstr(Buttons[i].label, "GARAG") != NULL)
                digitalWrite(ledPin[i], !digitalRead(ledPin[i]));

            if (strstr(Buttons[i].label, "PORTA") != NULL)
                servo.write((servo.read() == -1) ? 180 : 0);

            Buttons[i].state = !Buttons[i].state;
            touchInterval = millis();

            display.fillRect(Buttons[i].coordX, Buttons[i].coordY, Buttons[i].width, Buttons[i].height, (Buttons[i].state) ? TFT_GREEN : TFT_BLUE);
            display.setCursor(Buttons[i].coordX, Buttons[i].coordY + 10);
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