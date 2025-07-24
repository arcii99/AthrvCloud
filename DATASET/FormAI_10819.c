//FormAI DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365

// Function to generate random temperature
float generateTemperature() {
    return ((float)rand()/(float)(RAND_MAX))*50.0 - 10.0; // range of -10 to 40 degrees Celsius
}

int main() {
    srand(time(0)); // seed the random number generator with current time
    
    float temperature[MAX_DAYS]; // to store temperature for each day of the year
    
    // generate temperature for each day of the year
    for(int i=0; i<MAX_DAYS; i++) {
        temperature[i] = generateTemperature();
    }
    
    // display temperature for each day of the year
    printf("Temperature for each day:\n");
    for(int i=0; i<MAX_DAYS; i++) {
        printf("Day %d: %.2f degrees Celsius\n", i+1, temperature[i]);
    }

    // calculate average temperature for the year
    float sum = 0;
    for(int i=0; i<MAX_DAYS; i++) {
        sum += temperature[i];
    }
    float avgTemperature = sum/MAX_DAYS;
    
    // display the average temperature for the year
    printf("\nAverage temperature for the year: %.2f degrees Celsius\n", avgTemperature);
    
    return 0;
}