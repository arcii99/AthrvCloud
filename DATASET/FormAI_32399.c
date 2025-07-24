//FormAI DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HOURS 24
#define MAX_TEMPERATURE 50

void simulateWeather(int temperature[MAX_HOURS], int hours) {
    srand(time(NULL)); // Seed the random number generator with current time
    int currentTemperature = rand() % MAX_TEMPERATURE;
    temperature[0] = currentTemperature; // Set initial temperature as random

    printf("Hour\tTemperature\n");
    printf("0\t%d\n", temperature[0]);

    for (int i = 1; i < hours; i++) {
        // Generate a random number between -3 and 3
        int change = rand() % 7 - 3;
        currentTemperature += change;

        // Ensure temperature doesn't exceed limits
        if (currentTemperature > MAX_TEMPERATURE) {
            currentTemperature = MAX_TEMPERATURE;
        } else if (currentTemperature < 0) {
            currentTemperature = 0;
        }
        temperature[i] = currentTemperature;

        printf("%d\t%d\n", i, temperature[i]);
    }
}

int main() {
    int hours;

    printf("How many hours of weather simulation would you like to see?\n");
    scanf("%d", &hours);

    int temperature[hours];

    simulateWeather(temperature, hours);

    return 0;
}