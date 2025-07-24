//FormAI DATASET v1.0 Category: Weather simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int simulateWeather(int day, float temperature, int clouds) {
    // base case
    if (day == 0) {
        printf("Simulation complete - final temperature: %.2f, final clouds: %d\n", temperature, clouds);
        return 0;
    }

    // calculate temperature change
    float temperatureChange = ((float)rand()/(float)(RAND_MAX)) * 10 - 5;
    temperature += temperatureChange;

    // calculate cloud cover change
    int cloudChange = rand() % 3 - 1;
    clouds += cloudChange;

    // check for extreme weather events
    if (temperature < -10 || temperature > 40) {
        printf("Extreme temperatures!! Simulation terminated - temperature: %.2f\n", temperature);
        return 0;
    }
    if (clouds < 0 || clouds > 100) {
        printf("Extreme cloud cover!! Simulation terminated - clouds: %d\n", clouds);
        return 0;
    }

    // print current weather
    printf("Day %d: temperature: %.2f, clouds: %d%%\n", day, temperature, clouds);

    // recursively call with updated weather variables
    simulateWeather(day - 1, temperature, clouds);
}

int main() {
    // initialize random seed
    srand(time(NULL));

    // initialize starting weather variables
    int startingDay = 7;
    float startingTemp = 20.0;
    int startingClouds = 50;

    // start weather simulation
    simulateWeather(startingDay, startingTemp, startingClouds);

    return 0;
}