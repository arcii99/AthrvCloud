//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Define the upper and lower limits of the temperature range (in degrees Celsius)
#define MIN_TEMP 10
#define MAX_TEMP 40

// Define the number of temperature readings to take
#define NUM_READINGS 100

// Define the maximum allowable deviation from the target temperature (in degrees Celsius)
#define MAX_DEVIATION 0.25


int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Declare variables to store the temperature readings and the running sum
    double temperature_readings[NUM_READINGS];
    double sum = 0;

    // Generate the temperature readings and add them to the running sum
    for (int i = 0; i < NUM_READINGS; i++) {
        // Generate a random temperature between MIN_TEMP and MAX_TEMP (inclusive)
        double temperature = (double) rand() / RAND_MAX * (MAX_TEMP - MIN_TEMP) + MIN_TEMP;

        // Print each temperature reading to the console
        printf("Temperature reading %d: %.2f °C\n", i + 1, temperature);

        // Add the temperature to the running sum
        sum += temperature;

        // Store the temperature reading in the array
        temperature_readings[i] = temperature;
    }

    // Calculate the average temperature
    double average_temperature = sum / NUM_READINGS;

    // Print the average temperature to the console
    printf("Average temperature: %.2f °C\n", average_temperature);

    // Check if any of the temperature readings deviate from the target temperature by more than MAX_DEVIATION
    int num_errors = 0;
    for (int i = 0; i < NUM_READINGS; i++) {
        double deviation = abs(temperature_readings[i] - average_temperature);

        if (deviation > MAX_DEVIATION) {
            // Print an error message to the console
            printf("Error: Temperature reading %d deviates from the average by more than %.2f degrees\n", i + 1, MAX_DEVIATION);

            // Increment the error count
            num_errors++;
        }
    }

    // Print the total number of errors to the console
    printf("Total errors: %d\n", num_errors);

    // Return 0 to indicate successful program completion
    return 0;
}