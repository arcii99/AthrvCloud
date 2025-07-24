//FormAI DATASET v1.0 Category: Weather simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature, humidity;
    srand(time(NULL));

    // Generate random weather conditions
    temperature = rand() % 31 - 10;
    humidity = rand() % 81;

    // Check if it's a happy weather
    if (temperature >= 18 && temperature <= 25 && humidity >= 40 && humidity <= 60) {
        printf("Today's weather is perfect! It's %d degrees Celsius and the humidity is %d%%.\n", temperature, humidity);
        return 0;
    }

    // If it's not happy, simulate change in weather to make it happy
    printf("Today's weather is not so happy :( It's %d degrees Celsius and the humidity is %d%%.\n", temperature, humidity);

    while (temperature < 18 || temperature > 25 || humidity < 40 || humidity > 60) {
        // Simulating temperature change
        if (temperature < 18) {
            temperature += rand() % 5;
        } else if (temperature > 25) {
            temperature -= rand() % 5;
        }

        // Simulating humidity change
        if (humidity < 40) {
            humidity += rand() % 10;
        } else if (humidity > 60) {
            humidity -= rand() % 10;
        }

        printf("Weather is improving! It's now %d degrees Celsius and the humidity is %d%%.\n", temperature, humidity);
    }

    printf("Yay! The weather is now perfect! It's %d degrees Celsius and the humidity is %d%%.\n", temperature, humidity);

    return 0;
}