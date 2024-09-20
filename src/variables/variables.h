#ifndef VARIABLES_H
#define VARIABLES_H

#include <stdint.h>

extern const uint8_t ledPin[4];
extern const uint8_t proximitySensorPin;
extern const uint8_t servoPin;
extern unsigned long ledInterval;
extern unsigned long servoInterval;
extern unsigned long touchInterval;
extern uint16_t x;
extern uint16_t y;

#endif