#include <stdint.h>

/* / Definição dos pinos | Pins Definition:
 * GPIO: 17, 32, 33, 25, 26, 27 -> LEDs
 * GPIO  35 -> Proximity Sensor
 * GPIO  13 -> Servo
 * GPIO  22 -> Buzzer
 * GPIO  14 -> DHT11
 *
 * Pinos declarados em "User.Setup.h" de TFT_eSPI | Pins declared in TFT_eSPI's User_Setup.h:
 * GPIO  19 -> TFT_MISO / TOUCH_DO (T_DO)
 * GPIO  23 -> TFT_MOSI / TOUCH_DIN (T_DIN)
 * GPIO  18 -> TFT_SCLK / TOUCH_CLK (T_CLK)
 * GPIO  15 -> TFT_CS
 * GPIO  2 -> TFT_DC
 * GPIO  4 -> TFT_RST
 * GPIO  21 -> TOUCH_CS (T_CS)
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

// O intervalo em milissegundos em que o usuário pode apertar o botão | The interval in milliseconds that the user can press the touch button
unsigned long touchInterval;

// O intervalo em milissegundos em que o buzzer ficará acionado | The interval in milliseconds that the buzzer will be active
unsigned long alarmInterval;

// O intervalo em milissegundos em que o DHT irá checar os valores de temperatura e umidade | The interval in milliseconds that the DHT will check the temperature and humidity values
unsigned long dhtInterval;

// Estado do alarme | Alarm state
uint8_t alarmActive = 0;

// Variáveis de coordenadas do touch | Touch coordinate variables:
uint16_t x = 0, y = 0;

// Checa se o usuário não apertou algum botão ou se ele está pressionando o display fora da área dos botões | Check if the user didn't press any button or is currently pressing the display but not the button.
bool noButtonClick = false;