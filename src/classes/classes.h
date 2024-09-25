#ifndef CLASSES_H
#define CLASSES_H

#include <ESP32Servo.h>
#include <TFT_eSPI.h>
#include "DisplayBT/DisplayBT.h"
#include <Adafruit_FT6206.h>

extern Servo servo;
extern TFT_eSPI display;
extern DisplayBT Button1;
extern DisplayBT Button2;
extern Adafruit_FT6206 ts;

#endif