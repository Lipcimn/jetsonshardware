#ifndef VARIABLES_H
#define VARIABLES_H

#include <stdint.h>

extern const uint8_t ledPin[10];
extern const uint8_t pirPin;
extern const uint8_t servoPin;
extern const uint8_t buzzerPin;
extern unsigned long ledInterval;
extern unsigned long servoInterval;
extern unsigned long touchInterval;
extern unsigned long alarmInterval;
extern uint8_t BtnState_LED1;
extern uint8_t BtnState_LED2;
extern uint8_t BtnState_LED3;
extern uint8_t BtnState_LED4;
extern uint8_t BtnState_LED5;
extern uint8_t BtnState_LED6;
extern uint8_t BtnState_LED7;
extern uint8_t BtnState_LED8;
extern uint8_t BtnState_LED9;
extern uint8_t BtnState_LED10;
extern uint8_t BtnState_SERVO;
extern uint8_t alarmActive;
extern bool noButtonClick;
extern uint16_t x;
extern uint16_t y;

#endif