#include "variables/variables.h"
#include "classes/classes.h"

/**
 * Checa os valores de temperatura e umidade do DHT11 | Checks the DHT11 humidity and temperature values
 */
void temperatureAndHumidity(uint16_t milliseconds)
{
    if (millis() - dhtInterval <= milliseconds)
        return;

    temperature = dht.readTemperature();
    humidity = dht.readHumidity();

    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Umidade: ");
    Serial.print(humidity);
    Serial.println(" %");

    /*
     * Checa se os último valores armazenados diferem do valor atuais de temperatura e umidade.
     * Isso previne o fato de ter que atualizar o display com os valores sem parar
     *
     * Checks if current last values differs from updated temperature and humidity values
     * This prevents having to update the values on the display all the time
     */
    if (currentHumidity != humidity)
    {
        display.setCursor(humidLabel.coordX, humidLabel.coordY);
        display.fillRect(humidLabel.coordX, humidLabel.coordY, humidLabel.width, humidLabel.height, humidLabel.color);

        display.print("Umidade: ");
        display.print(humidity);
        display.print("%");

        currentHumidity = humidity;
    }

    if (currentTemperature != temperature)
    {
        display.setCursor(tempLabel.coordX, tempLabel.coordY);
        display.fillRect(tempLabel.coordX, tempLabel.coordY, tempLabel.width, tempLabel.height, tempLabel.color);

        display.print("Temperatura: ");
        display.print(temperature);
        display.print(" C");

        currentTemperature = temperature;
    }

    dhtInterval = millis();
}