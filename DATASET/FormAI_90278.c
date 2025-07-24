//FormAI DATASET v1.0 Category: Weather simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMPERATURE_RANGE 40
#define HUMIDITY_RANGE 100

int main() {
    srand(time(NULL));

    int temperature = 20;
    int humidity = 50;

    printf("Current temperature: %d C\n", temperature);
    printf("Current humidity: %d %%\n\n", humidity);

    for (int i = 0; i < 10; i++) {
        int temperature_change = rand() % TEMPERATURE_RANGE - TEMPERATURE_RANGE / 2;
        int humidity_change = rand() % HUMIDITY_RANGE - HUMIDITY_RANGE / 2;

        temperature += temperature_change;
        if (temperature < -20) {
            temperature = -20;
        } else if (temperature > 40) {
            temperature = 40;
        }

        humidity += humidity_change;
        if (humidity < 0) {
            humidity = 0;
        } else if (humidity > 100) {
            humidity = 100;
        }

        printf("After one hour:\n");
        printf("Temperature: %d C\n", temperature);
        printf("Humidity: %d %%\n\n", humidity);
    }

    return 0;
}