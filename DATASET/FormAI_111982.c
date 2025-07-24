//FormAI DATASET v1.0 Category: Weather simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulateWeather(int currentDay, int currentTemperature, int currentHumidity, int currentRainfall) {
    // base case: simulate weather for 7 days
    if(currentDay > 7) {
        printf("Simulation completed.\n");
        return;
    }

    printf("Day %d\n", currentDay);
    printf("Temperature: %d C\n", currentTemperature);
    printf("Humidity: %d %%\n", currentHumidity);
    printf("Rainfall: %d mm\n\n", currentRainfall);

    // simulate temperature change
    int temperatureChange = rand() % 5 - 2; // random temperature change between -2 to 2 degrees
    int newTemperature = currentTemperature + temperatureChange;

    // simulate humidity change
    int humidityChange = rand() % 10 - 4; // random humidity change between -4 to 5 percent
    int newHumidity = currentHumidity + humidityChange;

    // simulate rainfall change
    int rainfallChange = rand() % 10 - 6; // random rainfall change between -6 to 3 mm
    int newRainfall = currentRainfall + rainfallChange;

    simulateWeather(currentDay + 1, newTemperature, newHumidity, newRainfall);
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    // simulate weather for the first day
    int initialTemperature = 25; // initial temperature of 25 degrees Celsius
    int initialHumidity = 70; // initial humidity of 70 percent
    int initialRainfall = 5; // initial rainfall of 5 mm
    simulateWeather(1, initialTemperature, initialHumidity, initialRainfall);

    return 0;
}