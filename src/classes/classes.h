#ifndef CLASSES_H
#define CLASSES_H

#include <Servo.h>
#include <TFT_eSPI.h>
#include "DisplayBT/DisplayBT.h"

extern Servo servo;
extern TFT_eSPI tft;
extern DisplayBT Button1(0, 0, 320, 240);

#endif