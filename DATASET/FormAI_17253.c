//FormAI DATASET v1.0 Category: Temperature monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE 0

// Function to generate random temperature between min and max temperature range
int generateRandTemp(int minTemp, int maxTemp) {
    return (rand() % (maxTemp - minTemp + 1)) + minTemp;
}

int main() {
    srand(time(NULL)); // Set random seed based on system time

    int temperature; // Temperature variable

    // Infinite loop to monitor temperature every 2 seconds
    while(1) {
        temperature = generateRandTemp(MIN_TEMPERATURE, MAX_TEMPERATURE); // Get random temperature

        printf("Current Temperature: %dC\n", temperature); // Print current temperature

        // Check if temperature is too high or too low
        if(temperature > 80) {
            printf("WARNING: Temperature is above recommended range.\n");
        } else if (temperature < 20) {
            printf("WARNING: Temperature is below recommended range.\n");
        }

        sleep(2); // Sleep for 2 seconds before checking temperature again
    }

    return 0;
}