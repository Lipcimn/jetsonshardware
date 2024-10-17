#ifndef VARIABLES_H
#define VARIABLES_H

#include <stdint.h>

extern const uint8_t ledPin[6];
extern const uint8_t pirPin;
extern const uint8_t servoPin;
extern const uint8_t buzzerPin;

extern const uint8_t dhtPin;
extern uint16_t temperature;
extern uint16_t humidity;
extern uint16_t currentTemperature;
extern uint16_t currentHumidity;

extern unsigned long ledInterval;
extern unsigned long servoInterval;
extern unsigned long touchInterval;
extern unsigned long alarmInterval;
extern unsigned long dhtInterval;

extern uint8_t alarmActive;

extern bool noButtonClick;

extern uint16_t x;
extern uint16_t y;

#endif