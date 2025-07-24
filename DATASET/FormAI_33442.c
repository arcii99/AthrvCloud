//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature;
    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Temperature Monitor:\n");

    // Loop for 50 iterations
    for (int i = 0; i < 50; i++) {
        temperature = rand() % 101 - 50; // Generate a random temperature between -50 and 50 degrees Celsius
        printf("Iteration %d: Temperature = %d degrees Celsius\n", i+1, temperature);

        // Check if the temperature is above 0 degrees Celsius
        if (temperature > 0) {
            printf("Warning: Temperature above freezing point.\n");
        }

        // Check if the temperature is below -20 degrees Celsius
        if (temperature < -20) {
            printf("Warning: Temperature dangerously low.\n");
        }

        // Wait for 1 second
        sleep(1);
    }

    return 0;
}