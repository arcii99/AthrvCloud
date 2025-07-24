//FormAI DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE 0

void simulateWeather(int numDays);
int generateTemperature();

int main() {
    int numDays;

    printf("How many days of weather data would you like to simulate? ");
    scanf("%d", &numDays);

    simulateWeather(numDays);

    return 0;
}

void simulateWeather(int numDays) {
    int temperature[numDays];
    int totalTemp = 0;
    float avgTemp;

    srand(time(NULL));

    for (int i = 0; i < numDays; i++) {
        temperature[i] = generateTemperature();
        totalTemp += temperature[i];
        printf("Temperature on day %d: %d\n", i+1, temperature[i]);
    }

    avgTemp = totalTemp / (float)numDays;
    printf("Average temperature over %d days: %.2f\n", numDays, avgTemp);
}

int generateTemperature() {
    int temperature = (rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1)) + MIN_TEMPERATURE;
    return temperature;
}