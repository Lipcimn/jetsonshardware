#include "classes.h"

Servo servo;
TFT_eSPI display;
DisplayBT ButtonLED1(5, 5, 50, 50, "LED1");
DisplayBT ButtonLED2(65, 5, 50, 50, "LED2");
DisplayBT ButtonLED3(125, 5, 50, 50, "LED3");
DisplayBT ButtonLED4(185, 5, 50, 50, "LED4");
DisplayBT ButtonLED5(5, 65, 50, 50, "LED5");
DisplayBT ButtonLED6(65, 65, 50, 50, "LED6");
DisplayBT ButtonLED7(125, 65, 50, 50, "LED7");
DisplayBT ButtonLED8(185, 65, 50, 50, "LED8");
DisplayBT ButtonLED9(5, 125, 50, 50, "LED9");
DisplayBT ButtonLED10(65, 125, 50, 50, "LED10");
DisplayBT ButtonSERVO(5, 185, 50, 50, "SERVO");
DisplayBT Buttons[11] = {ButtonLED1, ButtonLED2, ButtonLED3, ButtonLED4, ButtonLED5, ButtonLED6, ButtonLED7, ButtonLED8, ButtonLED9, ButtonLED10, ButtonSERVO};
Adafruit_FT6206 ts = Adafruit_FT6206();
