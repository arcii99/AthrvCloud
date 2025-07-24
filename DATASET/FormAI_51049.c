//FormAI DATASET v1.0 Category: Temperature monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random float between min and max
float randomFloat(float min, float max) {
    return ((float) rand() / RAND_MAX) * (max - min) + min;
}

int main() {
    float temperature = 0.0;
    int i;

    // Initialize the random number generator with the current time
    srand(time(NULL));

    // Continuously monitor the temperature
    while (1) {
        // Generate a random temperature between 10°C and 30°C
        temperature = randomFloat(10.0, 30.0);

        // Print the current temperature
        printf("Current temperature: %.2f°C\n", temperature);

        // Check if the temperature is below 15°C or above 25°C
        if (temperature < 15.0) {
            printf("WARNING: Temperature is too low! Adjust the heating system.\n");
        } else if (temperature > 25.0) {
            printf("WARNING: Temperature is too high! Adjust the cooling system.\n");
        }

        // Wait for 5 seconds before checking the temperature again
        for (i = 0; i < 5; i++) {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        printf("\n");
    }

    return 0;
}