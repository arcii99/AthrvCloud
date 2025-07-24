//FormAI DATASET v1.0 Category: Temperature monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

int main(void) {
    int current_temp = 0;
    int min_temp = INT_MAX;
    int max_temp = INT_MIN;
    int total_temp = 0;
    int num_readings = 0;
    int target_temp = 24;
    bool is_target_reached = false;

    printf("Welcome to the Temperature Monitor Program\n\n");
    printf("The current target temperature is %d degrees Celsius.\n\n", target_temp);

    // Start monitoring temperature
    srand(time(NULL)); // Seed random number generator
    while(!is_target_reached) {
        current_temp = rand() % 40; // Simulate a temperature reading between 0-40
        printf("Current temperature: %d degrees Celsius.\n", current_temp);

        // Update minimum and maximum temperature readings
        if(current_temp < min_temp) {
            min_temp = current_temp;
        }
        if(current_temp > max_temp) {
            max_temp = current_temp;
        }

        // Calculate running total and number of temperature readings
        total_temp += current_temp;
        num_readings++;

        if(current_temp == target_temp) {
            printf("Target temperature of %d degrees Celsius has been reached!\n", target_temp);
            is_target_reached = true;
        }
    }

    // Output temperature statistics
    printf("\nTemperature Readings:\n");
    printf("Minimum: %d degrees Celsius.\n", min_temp);
    printf("Maximum: %d degrees Celsius.\n", max_temp);
    printf("Average: %.2f degrees Celsius.\n", (float) total_temp / num_readings);

    return EXIT_SUCCESS;
}