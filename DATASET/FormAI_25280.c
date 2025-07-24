//FormAI DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Creating a random temperature value between 0 to 100 (in degrees Celsius)
    srand(time(NULL));
    int temperature = rand() % 101;

    // Displaying the temperature value on the console
    printf("Current Temperature: %d°C\n", temperature);

    // Checking if the current temperature is below freezing
    if (temperature < 0) {
        printf("Warning: The temperature is below freezing point!\n");
    }

    // Checking if the current temperature is above boiling point
    if (temperature > 100) {
        printf("Warning: The temperature is above boiling point!\n");
    }

    // Checking if the temperature is within the ideal range of 20-25 degrees Celsius
    if (temperature >= 20 && temperature <= 25) {
        printf("The temperature is within the ideal range!\n");
    } else {
        printf("The temperature is not within the ideal range!\n");
    }

    return 0;
}