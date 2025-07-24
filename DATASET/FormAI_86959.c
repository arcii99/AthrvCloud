//FormAI DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float temp = 0.0;
    int upperLimit = 40;
    int lowerLimit = 20;

    srand(time(NULL)); // Seed random number generator with current time

    while(1) {
        temp = lowerLimit + ((float)rand()/(float)(RAND_MAX))* (upperLimit - lowerLimit); // Generate random temperature between 20 and 40

        printf("Current temperature: %.2f°C\n", temp); // Display temperature with 2 decimal places

        if (temp > 35.0) {
            printf("WARNING: Temperature is higher than the optimal range! Take appropriate action to bring the temperature down.\n");
        } else if (temp < 25.0) {
            printf("WARNING: Temperature is lower than the optimal range! Take appropriate action to bring the temperature up.\n");
        } else {
            printf("Temperature is in optimal range.\n");
        }

        printf("\n");

        sleep(5); // Wait for 5 seconds before checking temperature again
    }
    return 0;
}