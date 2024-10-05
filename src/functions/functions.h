#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdint.h>
#include <string.h>

extern void ledFunctionality(uint16_t milliseconds);
extern void servoFunctionality(uint16_t milliseconds);
extern void touch();
extern void alarm(uint16_t milliseconds);
extern void temperatureAndHumidity(uint16_t milliseconds);

#endif