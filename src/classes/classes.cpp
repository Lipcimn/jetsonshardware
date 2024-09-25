#include "classes.h"

Servo servo;
TFT_eSPI display;
DisplayBT ButtonLED1(5, 5, 50, 50);
DisplayBT ButtonLED2(65, 5, 50, 50);
DisplayBT ButtonLED3(125, 5, 50, 50);
DisplayBT ButtonLED4(185, 5, 50, 50);
DisplayBT ButtonLED5(5, 65, 50, 50);
DisplayBT ButtonLED6(65, 65, 50, 50);
DisplayBT ButtonLED7(125, 65, 50, 50);
DisplayBT ButtonLED8(185, 65, 50, 50);
DisplayBT ButtonLED9(30, 10, 50, 50);
DisplayBT ButtonLED10(30, 10, 50, 50);
DisplayBT ButtonSERVO(5, 150, 50, 50);
Adafruit_FT6206 ts = Adafruit_FT6206();
