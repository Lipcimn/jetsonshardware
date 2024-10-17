#include <stdint.h>

/* Pins Definition:
 * 1, 2, 3, 4 -> LEDs
 * 12 -> Proximity Sensor
 * 13 -> Servo
 */

extern const uint8_t ledPin[6] = {17, 32, 33, 25, 26, 27};
extern const uint8_t pirPin = 35;
extern const uint8_t servoPin = 13;
extern const uint8_t buzzerPin = 22;

extern const uint8_t dhtPin = 14;

uint16_t temperature;
uint16_t humidity;

uint16_t currentTemperature;
uint16_t currentHumidity;

// The interval in milliseconds that the user can press the touch button
unsigned long touchInterval;

// The interval in milliseconds that the buzzer will be active
unsigned long alarmInterval;

// The interval in milliseconds that the DHT will check the temperature and humidity values
unsigned long dhtInterval;

// Alarm state
uint8_t alarmActive = 0;

// Touch coordinate variables:
uint16_t x = 0, y = 0;

// Check if the user didn't press any button or is currently pressing the display but not the button.
bool noButtonClick = false;