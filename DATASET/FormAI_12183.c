//FormAI DATASET v1.0 Category: Weather simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A function to generate a random temperature within a given range
double generateTemperature(double min, double max) {
    double temperature = (double)rand() / RAND_MAX;
    temperature = min + temperature * (max - min);
    return temperature;
}

// The main function
int main() {
    // Set the minimum and maximum temperature range
    double minTemperature = -10.0;
    double maxTemperature = 40.0;
    // Set the number of days to simulate
    int numDays = 30;
    // Initialize random number generator
    srand(time(NULL));
    // Print the header
    printf("Day\tTemperature\n");
    // Loop through each day and generate a random temperature
    for (int i = 1; i <= numDays; i++) {
        double temperature = generateTemperature(minTemperature, maxTemperature);
        printf("%d\t%.1f\n", i, temperature);
    }
    return 0;
}