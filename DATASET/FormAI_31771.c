//FormAI DATASET v1.0 Category: Weather simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temp, wind_speed, humidity;
    srand(time(NULL));

    temp = rand() % 21 + 15; //generate random temperature between 15°C and 35°C
    wind_speed = rand() % 21; //generate random wind speed between 0 km/h and 20 km/h
    humidity = rand() % 81 + 20; //generate random humidity between 20% and 100%

    printf("Today's weather simulation:\n");
    printf("Temperature: %dC\n", temp);
    printf("Wind speed: %dkm/h\n", wind_speed);
    printf("Humidity: %d%%\n", humidity);
    
    // weather condition statements
    if (temp <= 20 && wind_speed <= 10 && humidity <= 50) {
        printf("Clear skies and cool weather.\n");
    } else if (humidity >= 70 && temp >= 25) {
        printf("Expect thunderstorms and heavy rain.\n");
    } else if (wind_speed >= 15 && temp >= 30) {
        printf("Hot and dry with a chance of sandstorms.\n");
    } else {
        printf("Nothing unusual to report.\n");
    }

    return 0;
}