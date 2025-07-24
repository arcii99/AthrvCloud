//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// function to get the current temperature
double get_temperature() {
    // Generate a random temperature between 0 to 100
    double temperature = ((double) rand() / (RAND_MAX)) * 100;
    return temperature;
}

// main function
int main() {
    // Define variables and constants
    const int MAX_READINGS = 10; // Maximum number of temperature readings to be taken
    double temperature = 0.0;    // Temperature variable to hold current temperature
    double max_temperature = 0.0; // Maximum temperature variable
    double min_temperature = 100.0; // Minimum temperature variable
    double total_temperature = 0.0; // Total temperature variable for calculating average
    int i = 0; // Loop variable for taking temperature readings

    // Display greeting message
    printf("Welcome to the Ultra-Precise Temperature Monitor\n\n");

    // Get temperature readings
    for(i = 0; i < MAX_READINGS; i++) {
        // Get current temperature
        temperature = get_temperature();

        // Print current temperature
        printf("Reading %d: %.2lf\n", i+1, temperature);

        // Update maximum temperature
        if(temperature > max_temperature) {
            max_temperature = temperature;
        }

        // Update minimum temperature
        if(temperature < min_temperature) {
            min_temperature = temperature;
        }

        // Add temperature to total 
        total_temperature += temperature;
    }

    // Calculate average temperature
    double average_temperature = total_temperature / MAX_READINGS;

    // Display results
    printf("\nMaximum Temperature: %.2lf\n", max_temperature);
    printf("Minimum Temperature: %.2lf\n", min_temperature);
    printf("Average Temperature: %.2lf\n", average_temperature);

    // Exit program
    return 0;
}