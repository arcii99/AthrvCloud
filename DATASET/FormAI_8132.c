//FormAI DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 100

int main() {
    int numbers[ARRAY_SIZE], i;
    double mean = 0.0, variance = 0.0, standard_deviation = 0.0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate an array of random numbers
    printf("Random number array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % 100;
        printf("%d ", numbers[i]);
        mean += (double) numbers[i] / ARRAY_SIZE;
    }

    // Calculate the variance and standard deviation
    for (i = 0; i < ARRAY_SIZE; i++) {
        variance += pow((double) numbers[i] - mean, 2) / ARRAY_SIZE;
    }
    standard_deviation = sqrt(variance);

    // Output the mean, variance, and standard deviation
    printf("\n\nMean: %lf\nVariance: %lf\nStandard Deviation: %lf\n", mean, variance, standard_deviation);

    return 0;
}