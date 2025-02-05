#include "classes.h"

Servo servo;

TFT_eSPI display;

DisplayBT ButtonLED1(5, 5, 60, 60, "COZNH");
DisplayBT ButtonLED2(75, 5, 60, 60, "JANTA");
DisplayBT ButtonLED3(145, 5, 60, 60, "ESCRI");
DisplayBT ButtonLED4(5, 75, 60, 60, "SALA");
DisplayBT ButtonLED5(75, 75, 60, 60, "BANHO");
DisplayBT ButtonLED6(145, 75, 60, 60, "GARAG");
DisplayBT ButtonSERVO(240, 5, 60, 60, "PORTA");
DisplayBT ButtonALARM(240, 75, 60, 60, "ALARM");
DisplayBT Buttons[8] = {ButtonLED1, ButtonLED2, ButtonLED3, ButtonLED4, ButtonLED5, ButtonLED6, ButtonSERVO, ButtonALARM};

DisplayBT lastTouchedButton(0, 0, 0, 0, "NULL"); // Essa instância é usada para negar o efeito do usuário pressionar o mesmo botão indefinidamente |This instance is used to negate the effect of the user pressing the same button indefinitely.

DHT dht(dhtPin, DHT11);

DisplayLabel tempLabel(5, 135, 300, 16, TFT_BLACK);
DisplayLabel humidLabel(5.5, 155, 300, 16, TFT_BLACK);

// Caixa de label dos autores | Authors label box
DisplayLabel duduLabel(5, 180, 300, 16, TFT_BLACK);
DisplayLabel manuLabel(5.5, 200, 300, 16, TFT_BLACK);