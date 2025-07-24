//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 50
#define MIN_TEMP -20
#define MAX_WIND_SPEED 100

int main() {
    srand(time(NULL)); // Seed the random number generator

    int temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP; // choose a random temperature within the acceptable range
    int wind_speed = rand() % MAX_WIND_SPEED; // choose a random wind speed

    printf("The temperature is %d degrees Celsius and the wind speed is %d km/h.\n", temperature, wind_speed);

    if (temperature < 0 && wind_speed > 20) {
        printf("WARNING: Extremely low temperature and high wind speed present! Please stay indoors.\n");
    } else if (temperature < 0) {
        printf("WARNING: Extremely low temperature present! Dress warmly if going outside.\n");
    } else if (wind_speed > 20) {
        printf("WARNING: High wind speed present! Hold onto your hat.\n");
    } else if (temperature > 30) {
        printf("WARNING: Extremely high temperature present! Stay hydrated if going outside.\n");
    } else {
        printf("The weather is lovely today. Enjoy your day!\n");
    }

    return 0;
}