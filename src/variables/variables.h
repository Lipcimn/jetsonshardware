#ifndef VARIABLES_H
#define VARIABLES_H

#include <stdint.h>

extern const uint8_t ledPin[4];
extern const uint8_t pirPin;
extern const uint8_t servoPin;
extern const uint8_t buzzerPin;
extern unsigned long ledInterval;
extern unsigned long servoInterval;
extern unsigned long touchInterval;
extern unsigned long alarmInterval;
extern uint8_t ButtonLED;
extern uint8_t ButtonSERVO;
extern uint8_t alarmActive;
extern uint16_t x;
extern uint16_t y;

#endif