#ifndef CLASSES_H
#define CLASSES_H

#include <ESP32Servo.h>
#include <TFT_eSPI.h>
#include "DisplayBT/DisplayBT.h"
#include "DisplayLabel/DisplayLabel.h"
#include <Adafruit_FT6206.h>
#include <DHT.h>
#include <DHT_U.h>

#include "variables/variables.h"

extern Servo servo;
extern TFT_eSPI display;
extern DisplayBT ButtonLED1;
extern DisplayBT ButtonLED2;
extern DisplayBT ButtonLED3;
extern DisplayBT ButtonLED4;
extern DisplayBT ButtonLED5;
extern DisplayBT ButtonLED6;
extern DisplayBT ButtonLED7;
extern DisplayBT ButtonLED8;
extern DisplayBT ButtonSERVO;
extern DisplayBT Buttons[8];
extern DisplayBT lastTouchedButton;
extern Adafruit_FT6206 ts;
extern DHT dht;
extern DisplayLabel tempLabel;
extern DisplayLabel humidLabel;

#endif