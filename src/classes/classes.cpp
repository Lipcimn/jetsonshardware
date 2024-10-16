#include "classes.h"

Servo servo;

TFT_eSPI display;

DisplayBT ButtonLED1(5, 5, 60, 60, "LED1");
DisplayBT ButtonLED2(75, 5, 60, 60, "LED2");
DisplayBT ButtonLED3(145, 5, 60, 60, "LED3");
DisplayBT ButtonLED4(5, 75, 60, 60, "LED4");
DisplayBT ButtonLED5(75, 75, 60, 60, "LED5");
DisplayBT ButtonLED6(145, 75, 60, 60, "LED6");
DisplayBT ButtonSERVO(240, 5, 60, 60, "SERVO");
DisplayBT ButtonALARM (240, 75, 60, 60, "ALARM");
DisplayBT Buttons[8] = {ButtonLED1, ButtonLED2, ButtonLED3, ButtonLED4, ButtonLED5, ButtonLED6, ButtonSERVO, ButtonALARM};

DisplayBT lastTouchedButton(0, 0, 0, 0, "NULL"); // This instance is used to negate the effect of the user pressing the same button indefinitely.

Adafruit_FT6206 ts = Adafruit_FT6206();

DHT dht(dhtPin, DHT11);

DisplayLabel tempLabel(5, 165, 300, 16, TFT_BLACK);
DisplayLabel humidLabel(5.5, 185, 300, 16, TFT_BLACK);