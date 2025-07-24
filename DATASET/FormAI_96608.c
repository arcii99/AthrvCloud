//FormAI DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to Weather Simulator!\n\n");

    srand(time(NULL)); // set random seed

    float temperature = (rand() % 60) - 20; // generate random temperature from -20 to 40 Celsius
    float humidity = (rand() % 100) / 100.0; // generate random humidity from 0 to 1
    float pressure = (rand() % 50) + 950; // generate random pressure from 950 to 1000 hPa

    printf("Current temperature: %0.1fC\n", temperature);
    printf("Current humidity: %0.2f%%\n", humidity * 100);
    printf("Current pressure: %0.1fhPa\n\n", pressure);

    if (temperature > 0 && pressure > 1013.25 && humidity > 0.8) {
        printf("It's warm and humid, might rain soon.\n");
    }
    else if (temperature > 20 && pressure > 1013.25 && humidity < 0.4) {
        printf("It's dry and hot, might have a heat wave.\n");
    }
    else if (temperature < 0) {
        printf("It's freezing cold, snow might fall.\n");
    }
    else {
        printf("Current weather seems unpredictable, keep an eye on updates.\n");
    }

    return 0;
}