#include "classes.h"

Servo servo;

TFT_eSPI display;

DisplayBT ButtonLED1(5, 5, 50, 50, "LED1");
DisplayBT ButtonLED2(65, 5, 50, 50, "LED2");
DisplayBT ButtonLED3(125, 5, 50, 50, "LED3");
DisplayBT ButtonLED4(185, 5, 50, 50, "LED4");
DisplayBT ButtonLED5(5, 65, 50, 50, "LED5");
DisplayBT ButtonLED6(65, 65, 50, 50, "LED6");
DisplayBT ButtonSERVO(5, 185, 50, 50, "SERVO");
DisplayBT Buttons[7] = {ButtonLED1, ButtonLED2, ButtonLED3, ButtonLED4, ButtonLED5, ButtonLED6, ButtonSERVO};

DisplayBT lastTouchedButton(0, 0, 0, 0, "NULL"); // This instance is used to negate the effect of the user pressing the same button indefinitely.

Adafruit_FT6206 ts = Adafruit_FT6206();

DHT dht(dhtPin, DHT11);

DisplayLabel tempLabel(5, 260, 180, 8, TFT_BLACK);
DisplayLabel humidLabel(5.5, 250, 180, 8, TFT_BLACK);