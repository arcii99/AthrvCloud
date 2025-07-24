//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random float number between 0 and 100
float get_random_temperature() {
    float temp = ((float)rand()/(float)(RAND_MAX)) * 100;
    return temp;
}

int main() {
    int count = 0;
    float temperature = 0;
    float average_temperature = 0;
    float max_temperature = 0;
    float min_temperature = 100;

    // Set the seed for the random number generator
    srand(time(NULL));

    printf("Starting temperature monitor...\n");

    // Loop through 100 temperature readings
    while (count < 100) {
        temperature = get_random_temperature();

        // Update the average temperature
        average_temperature = (average_temperature * count + temperature) / (float)(count + 1);

        // Check if this temperature is higher or lower than the current max or min temperature
        if (temperature > max_temperature) {
            max_temperature = temperature;
        }
        if (temperature < min_temperature) {
            min_temperature = temperature;
        }

        // Print out the current temperature reading
        printf("Temperature reading %d: %.2f C\n", count+1, temperature);

        count++;
    }

    // Print out the final results
    printf("\n--- Temperature Monitor Results ---\n");
    printf("Total number of temperature readings: %d\n", count);
    printf("Average temperature: %.2f C\n", average_temperature);
    printf("Max temperature: %.2f C\n", max_temperature);
    printf("Min temperature: %.2f C\n", min_temperature);

    return 0;
}