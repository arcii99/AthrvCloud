//FormAI DATASET v1.0 Category: Weather simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // sets the seed for random values

    int forecast = rand() % 4;  // generates a random number between 0-3 inclusive
    int temperature = rand() % 71 - 20;  // generates a random number between -20-50 inclusive

    switch (forecast) {
        case 0:
            printf("It's a beautiful sunny day today!\n");
            break;
        case 1:
            printf("We're expecting cloudy skies today.\n");
            break;
        case 2:
            printf("It looks like it'll be raining all day today.\n");
            break;
        case 3:
            printf("There's a chance of a thunderstorm later today.\n");
            break;
        default:
            printf("Oops, something went wrong with the weather forecast.\n");
            break;
    }

    printf("The temperature is currently %d degrees Celsius.\n", temperature);

    if (temperature < 0) {
        printf("It's freezing out there, make sure to bundle up!\n");
    } else if (temperature >= 0 && temperature <= 10) {
        printf("It's quite chilly outside, make sure to wear a jacket.\n");
    } else if (temperature > 10 && temperature <= 20) {
        printf("It's a comfortable temperature outside, enjoy the day!\n");
    } else if (temperature > 20 && temperature <= 30) {
        printf("It's getting quite warm out there, make sure to stay hydrated.\n");
    } else {
        printf("It's scorching hot outside, stay in the shade if possible.\n");
    }

    return 0;
}