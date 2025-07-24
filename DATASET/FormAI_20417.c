//FormAI DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Set up temperature variables and constants
    float current_temp = 23.0;
    const float MIN_TEMP = 18.0;
    const float MAX_TEMP = 27.0;

    // Set up measurement variables and constants
    const int NUM_MEASUREMENTS = 10;
    float temperatures[NUM_MEASUREMENTS];
    int i;

    // Set up time variables
    time_t t;
    srand((unsigned) time(&t));
    
    // Simulate taking temperature measurements
    for (i = 0; i < NUM_MEASUREMENTS; i++) {
        // Generate random temperature between minimum and maximum values
        float rand_temp = (float)rand() / RAND_MAX * (MAX_TEMP - MIN_TEMP) + MIN_TEMP;
        
        // Add random fluctuation to current temperature
        float temp_diff = rand_temp - current_temp;
        current_temp += temp_diff;
        
        // Add simulated measurement to array
        temperatures[i] = current_temp;
    }
    
    // Print out temperature measurements
    printf("Temperature Measurements:\n");
    for (i = 0; i < NUM_MEASUREMENTS; i++) {
        printf("%.1f degrees Celsius\n", temperatures[i]);
    }
    
    // Determine if temperature is within acceptable range
    if (current_temp < MIN_TEMP) {
        printf("\nWARNING: Temperature is too low! Current temperature is %.1f degrees Celsius.\n", current_temp);
    } else if (current_temp > MAX_TEMP) {
        printf("\nWARNING: Temperature is too high! Current temperature is %.1f degrees Celsius.\n", current_temp);
    } else {
        printf("\nTemperature is within acceptable range. Current temperature is %.1f degrees Celsius.\n", current_temp);
    }
    
    return 0;
}