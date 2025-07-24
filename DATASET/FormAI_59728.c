//FormAI DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Variables for weather conditions
    int temperature = rand() % 30 - 10; // Random temperature between -10 and 20 degrees Celsius
    int humidity = rand() % 100; // Random humidity percentage
    int wind_speed = rand() % 61; // Random wind speed between 0 and 60 km/h

    // Output weather conditions
    printf("Today's weather:\n");
    printf("- Temperature: %dC\n", temperature);
    printf("- Humidity: %d%%\n", humidity);
    printf("- Wind speed: %dkm/h\n", wind_speed);

    // Weather forecast for tomorrow
    int temp_change = rand() % 11 - 5; // Random temperature change between -5 and 5 degrees Celsius
    temperature += temp_change;
    humidity += rand() % 11 - 5; // Random humidity change between -5% and 5%
    wind_speed += rand() % 11 - 5; // Random wind speed change between -5 and 5 km/h

    // Output weather forecast for tomorrow
    printf("Tomorrow's forecast:\n");
    printf("- Temperature: %dC\n", temperature);
    printf("- Humidity: %d%%\n", humidity);
    printf("- Wind speed: %dkm/h\n", wind_speed);

    return 0;
}