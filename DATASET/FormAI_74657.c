//FormAI DATASET v1.0 Category: Weather simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));     // seed for random number generator
    int temperature = (rand() % 50) - 10;    // temperature range from -10 to 40 degrees Celsius
    float humidity = ((float)rand() / RAND_MAX) * 100;   // humidity range from 0 to 100 percent
    float pressure = ((float)rand() / RAND_MAX) * 100;   // pressure range from 0 to 100 kPa

    // Initial weather report
    printf("Initial weather report:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %.2f%%\n", humidity);
    printf("Pressure: %.2f kPa\n\n", pressure);

    // Temperature fluctuation during the day
    printf("Temperature fluctuation during the day:\n");
    for (int hour = 1; hour <= 24; hour++) {
        int temp_change = (rand() % 9) - 4;   // temperature fluctuations from -4 to +4 degrees Celsius
        if (temperature + temp_change > 40) {
            temperature = 40;   // maximum temperature is 40 degrees Celsius
        }
        else if (temperature + temp_change < -10) {
            temperature = -10;  // minimum temperature is -10 degrees Celsius
        }
        else {
            temperature += temp_change;
        }
        printf("%d:00 - Temperature: %d degrees Celsius\n", hour, temperature);
    }
    printf("\n");

    // Humidity and Pressure changes during the day
    printf("Humidity and Pressure changes during the day:\n");
    for (int hour = 1; hour <= 24; hour++) {
        float hum_change = ((float)rand() / RAND_MAX) * 10 - 5;   // humidity fluctuations from -5% to +5%
        float press_change = ((float)rand() / RAND_MAX) * 10 - 5; // pressure fluctuations from -5 kPa to +5 kPa
        humidity += hum_change;
        pressure += press_change;
        if (humidity > 100) {
            humidity = 100;   // maximum humidity is 100%
        }
        else if (humidity < 0) {
            humidity = 0;     // minimum humidity is 0%
        }
        if (pressure > 100) {
            pressure = 100;   // maximum pressure is 100 kPa
        }
        else if (pressure < 0) {
            pressure = 0;     // minimum pressure is 0 kPa
        }
        printf("%d:00 - Humidity: %.2f%%, Pressure: %.2f kPa\n", hour, humidity, pressure);
    }

    return 0;
}