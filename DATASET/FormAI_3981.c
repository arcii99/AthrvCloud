//FormAI DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdio.h>

#define TEMP_THRESHOLD 30.0f // Set temperature threshold

int main() {
    float temp = 0.0f; // Variable to hold temperature value
    int num_readings = 0; // Number of temperature readings
    float total_temp = 0.0f; // Total temperature value
    float avg_temp = 0.0f; // Average temperature value

    printf("Temperature Monitor\n");
    printf("-------------------\n");

    // Loop to read in temperature values
    while (num_readings < 10) {
        printf("Enter temperature reading #%d: ", num_readings + 1);
        scanf("%f", &temp);

        // Check if temperature is below threshold
        if (temp < TEMP_THRESHOLD) {
            printf("WARNING: Temperature below threshold of %.1f degrees Celsius.\n", TEMP_THRESHOLD);
        }

        // Add temperature to total
        total_temp += temp;
        num_readings++;
    }

    // Calculate average temperature
    avg_temp = total_temp / num_readings;

    // Output total and average temperature values
    printf("\nTotal temperature: %.1f degrees Celsius\n", total_temp);
    printf("Average temperature: %.1f degrees Celsius\n", avg_temp);

    return 0;
}