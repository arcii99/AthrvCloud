//FormAI DATASET v1.0 Category: Weather simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5

int main() {
    // Array to hold the temperature of each city
    int temperature[NUM_CITIES] = {0};

    // Seed the random number generator
    srand(time(NULL));

    // Populate the temperature array with random temperatures between 0 and 40
    for(int i = 0; i < NUM_CITIES; i++) {
        temperature[i] = rand() % 41;
    }

    // Display the initial temperatures of each city
    for(int i = 0; i < NUM_CITIES; i++) {
        printf("City %d: %d degrees Celsius\n", i+1, temperature[i]);
    }

    // Keep simulating the weather until the temperatures stabilize
    int stabilization_count = 0;
    while(stabilization_count < NUM_CITIES) {
        // Simulate one hour of weather changes for each city
        for(int i = 0; i < NUM_CITIES; i++) {
            int temperature_change = rand() % 5 - 2;    // Random temperature change between -2 and 2 degrees Celsius
            temperature[i] += temperature_change;

            // Ensure the temperature does not go below 0 or above 40 degrees Celsius
            if(temperature[i] < 0) {
                temperature[i] = 0;
            }
            else if(temperature[i] > 40) {
                temperature[i] = 40;
            }

            // Check if the temperature has stabilized for this city
            if(temperature_change == 0) {
                stabilization_count++;
            }
            else {
                stabilization_count = 0;
            }
        }

        // Display the new temperatures of each city
        printf("\n");
        for(int i = 0; i < NUM_CITIES; i++) {
            printf("City %d: %d degrees Celsius\n", i+1, temperature[i]);
        }

        // Wait for 1 second before simulating the next hour of weather changes
        sleep(1);
    }

    printf("\nThe weather has stabilized in all cities.\n");

    return 0;
}