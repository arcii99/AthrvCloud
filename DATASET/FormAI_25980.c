//FormAI DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp;
    int humidity;
    int pressure;

    srand(time(NULL));

    // Generate random values for temperature, humidity, and pressure
    temp = rand() % 100;
    humidity = rand() % 100;
    pressure = rand() % 1000;

    // Choose a random weather condition based on the temperature, humidity, and pressure values
    if (temp > 80 && humidity > 60 && pressure < 800) {
        printf("It's hot and humid with low pressure. Expect thunderstorms.\n");
    } else if (temp > 80 && humidity < 40 && pressure > 900) {
        printf("It's hot and dry with high pressure. Expect sunny skies.\n");
    } else if (temp < 50 && humidity > 70 && pressure > 1000) {
        printf("It's cold and damp with high pressure. Expect snowy weather.\n");
    } else if (temp < 50 && humidity < 30 && pressure > 1000) {
        printf("It's cold and dry with high pressure. Expect clear skies.\n");
    } else {
        printf("The weather is unpredictable!.\n");
    }

    return 0;
}