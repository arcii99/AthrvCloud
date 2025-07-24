//FormAI DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(NULL)); // seed for random number generator

    int n = 10;
    float nums[n];
    float sum = 0;
    float mean = 0;
    float variance = 0;
    float std_dev = 0;

    printf("Generating %d random numbers: ", n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = (float) (rand() % 100) / 10; // generate random float between 0 and 10
        printf("%g ", nums[i]);
        sum += nums[i];
    }
    printf("\n");

    /* Calculate Mean */
    mean = sum / n;

    /* Calculate Variance */
    for (int i = 0; i < n; i++)
    {
        variance += pow(nums[i] - mean, 2);
    }
    variance /= n;

    /* Calculate Standard Deviation */
    std_dev = sqrt(variance);

    printf("Mean: %g\n", mean);
    printf("Variance: %g\n", variance);
    printf("Standard Deviation: %g\n", std_dev);

    return 0;
}