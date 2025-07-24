//FormAI DATASET v1.0 Category: Weather simulation ; Style: Claude Shannon
/*
 * C Weather Simulation Program by Claude Shannon
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature = 0;
    int humidity = 0;
    int rain_chance = 0;
    int wind_speed = 0;

    srand(time(0)); // seed random number generator

    while(1) { // run simulation indefinitely
        printf("\n");
        printf("Temperature: %d°C\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Chance of Rain: %d%%\n", rain_chance);
        printf("Wind Speed: %d kph\n", wind_speed);

        temperature = rand() % 41 - 10; // generate random temperature between -10°C and 30°C
        humidity = rand() % 101; // generate random humidity between 0% and 100%
        rain_chance = rand() % 101; // generate random chance of rain between 0% and 100%
        wind_speed = rand() % 101; // generate random wind speed between 0 kph and 100 kph

        if (temperature > 20 && humidity > 60 && rain_chance > 50) { // if conditions are suitable for thunderstorm
            printf("\n");
            printf("Thunderstorm Alert!\n");
            printf("\n");
        }

        // wait for 5 seconds before running simulation again
        printf("\n");
        printf("Running Simulation...\n");
        printf("\n");

        int i = 5;
        while(i > 0) {
            printf("%d\n", i);
            sleep(1);
            i--;
        }
    }

    return 0;
}