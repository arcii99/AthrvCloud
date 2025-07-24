//FormAI DATASET v1.0 Category: Scientific ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_SAMPLES 100
#define LOWER_BOUND 1
#define UPPER_BOUND 10

int main()
{
    srand(time(NULL));

    // Generate random data
    float data[NUM_SAMPLES];
    for(int i=0; i<NUM_SAMPLES; i++) {
        data[i] = (float)(rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND);
    }

    // Find mean
    float sum = 0.0;
    float mean = 0.0;
    for(int i=0; i<NUM_SAMPLES; i++) {
        sum += data[i];
    }
    mean = sum / (float)NUM_SAMPLES;

    // Find standard deviation
    float variance = 0.0;
    float std_deviation = 0.0;
    for(int i=0; i<NUM_SAMPLES; i++) {
        variance += pow(data[i] - mean, 2);
    }
    variance /= (float)NUM_SAMPLES;
    std_deviation = sqrt(variance);

    // Print results
    printf("Generated %d random samples between %d and %d:\n", NUM_SAMPLES, LOWER_BOUND, UPPER_BOUND);
    for(int i=0; i<NUM_SAMPLES; i++) {
        printf("%.2f ", data[i]);
    }
    printf("\n\nMean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard deviation: %.2f\n", std_deviation);

    return 0;
}