//FormAI DATASET v1.0 Category: Weather simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int temperature = (rand() % 50) - 10;
    int rainfall = rand() % 101;
    int windSpeed = rand() % 51;
    int cloudCover = rand() % 101;

    printf("Welcome to Retro Weather Simulator!\n");
    printf("Today's temperature is %d degrees Celsius.\n", temperature);
    printf("There is a %d percent chance of rain today.\n", rainfall);
    printf("The wind speed is %d km/h.\n", windSpeed);
    printf("The cloud cover is %d percent.\n", cloudCover);

    if (rainfall > 50) {
        printf("It looks like it will be a rainy day. Don't forget your umbrella!\n");
    }
    if (temperature > 25) {
        printf("It's going to be a hot one today. Make sure to stay hydrated.\n");
    }
    if (windSpeed > 30) {
        printf("Watch out for strong winds today. Secure any loose objects outside.\n");
    }
    if (cloudCover > 75) {
        printf("It's going to be a cloudy day. Don't forget your jacket!\n");
    }

    printf("Thanks for using Retro Weather Simulator. Stay safe out there!\n");

    return 0;
}