//FormAI DATASET v1.0 Category: Temperature monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random temperature between -10 and 40 degrees Celsius
    int currentTemp = rand() % 51 - 10;

    // Print the current temperature
    printf("The current temperature is %d degrees Celsius.\n", currentTemp);

    // Check if temperature is too low or too high
    if (currentTemp < 0) {
        printf("It is freezing cold outside, make sure to dress warm!\n");
    } else if (currentTemp > 30) {
        printf("It is very hot outside, make sure to stay hydrated!\n");
    } else {
        printf("It is a beautiful day outside, enjoy it!\n");
    }

    return 0;
}