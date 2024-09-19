#include <Arduino.h>

/* Pins Definition:
 * 1, 2, 3, 4 -> LEDs
 * 12 -> Proximity Sensor
 * 13 -> Servo
 */
const uint8_t led[4] = {10, 11, 12, 13};
const uint8_t proximitySensor = 14;
const uint8_t servoPin = 13;