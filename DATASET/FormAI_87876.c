//FormAI DATASET v1.0 Category: Weather simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp, humidity, pressure;
    char condition[10];
    srand(time(NULL)); // Initialise random seed

    // Generate values for temperature, humidity, pressure
    temp = rand() % 100 - 50; // Temperature range: -50 to 50°C
    humidity = rand() % 101; // Humidity range: 0 to 100%
    pressure = rand() % 1013 + 990; // Pressure range: 990 to 2003 hPa

    // Determine the weather condition based on the temperature
    if (temp < -10) {
        sprintf(condition, "Snowstorm");
    } else if (temp < 5) {
        sprintf(condition, "Cold");
    } else if (temp < 20) {
        sprintf(condition, "Warm");
    } else {
        sprintf(condition, "Hot");
    }

    // Print out the weather report
    printf("Weather Report: \n");
    printf("Temperature: %d°C\n", temp);
    printf("Humidity: %d%%\n", humidity);
    printf("Pressure: %d hPa\n", pressure);
    printf("Condition: %s\n", condition);

    return 0;
}