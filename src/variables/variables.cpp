#include <stdint.h>

/* Pins Definition:
 * 1, 2, 3, 4 -> LEDs
 * 12 -> Proximity Sensor
 * 13 -> Servo
 */

extern const uint8_t ledPin[4] = {10, 11, 12, 17};
extern const uint8_t proximitySensorPin = 16;
extern const uint8_t servoPin = 14;

// The time in milliseconds that the LEDs will be on
unsigned long ledInterval;

// The time in milliseconds that the Servo will be on
unsigned long servoInterval;

// The interval in milliseconds that the user can press the touch button
unsigned long touchInterval;

// The touch button states
uint8_t ButtonLED = 0;
uint8_t ButtonSERVO = 0;

// Touch coordinate variables:
uint16_t x = 0, y = 0;