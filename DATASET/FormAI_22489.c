//FormAI DATASET v1.0 Category: Weather simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));        // Seed random number generator with current time
    int temperature = rand() % 101 - 50;    // Generate a random temperature between -50F to 50F

    // Display current temperature and weather condition based on temperature
    printf("The current temperature is %dF.\n", temperature);
    if (temperature < -20) {
        printf("It is extremely cold outside. Please dress warmly and limit your time outside.\n");
    } else if (temperature < 0) {
        printf("It is very cold outside. Please dress warmly and avoid prolonged exposure.\n");
    } else if (temperature < 20) {
        printf("It is cold outside. Please dress warmly and be careful on icy roads.\n");
    } else if (temperature < 40) {
        printf("It is cool outside. Please wear layers and enjoy the brisk weather.\n");
    } else if (temperature < 60) {
        printf("It is pleasant outside. Enjoy the mild weather and sunshine.\n");
    } else if (temperature < 80) {
        printf("It is warm outside. Stay hydrated and wear sunscreen if spending time in the sun.\n");
    } else if (temperature < 100) {
        printf("It is hot outside. Stay cool, stay hydrated, and avoid strenuous activity outside.\n");
    } else {
        printf("It is extremely hot outside. Avoid going outside and stay in air-conditioned spaces.\n");
    }

    return 0;
}