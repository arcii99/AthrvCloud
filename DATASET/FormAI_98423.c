//FormAI DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the maximum and minimum values for the data range
#define MAX_VALUE 100
#define MIN_VALUE -100

// Define the number of data points to generate
#define NUM_DATA_POINTS 1000

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate the data points
    double data[NUM_DATA_POINTS];
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        double value = ((double) rand() / RAND_MAX) * (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
        data[i] = value;
    }

    // Calculate the mean and standard deviation of the data
    double sum = 0;
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        sum += data[i];
    }
    double mean = sum / NUM_DATA_POINTS;

    double variance = 0;
    for (int i = 0; i < NUM_DATA_POINTS; i++) {
        variance += pow(data[i] - mean, 2);
    }
    double std_dev = sqrt(variance / NUM_DATA_POINTS);

    // Print out the results
    printf("Mean: %f\n", mean);
    printf("Standard deviation: %f\n", std_dev);

    return 0;
}