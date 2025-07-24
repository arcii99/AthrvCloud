//FormAI DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int i;
    double sum = 0.0, average, stddev = 0.0;
    double data[ARRAY_SIZE];

    srand(time(NULL));

    // Fill data array with random values between 0 and 1
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        data[i] = (double)rand() / RAND_MAX;
    }

    // Calculate sum of data values
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        sum += data[i];
    }

    // Calculate average of data values
    average = sum / ARRAY_SIZE;

    // Calculate standard deviation of data values
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        stddev += pow(data[i] - average, 2);
    }
    stddev = sqrt(stddev / ARRAY_SIZE);

    // Output results
    printf("Sum: %f\n", sum);
    printf("Average: %f\n", average);
    printf("Standard deviation: %f\n", stddev);

    return 0;
}