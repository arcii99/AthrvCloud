//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
A performance-critical component example program that generates
a random sequence of numbers and calculates their mean value.
*/

#define NUM_VALUES 1000000 // number of random values to generate

int main()
{
    // seed the random number generator
    srand(time(NULL));

    // generate a random sequence of numbers
    float values[NUM_VALUES];
    for (int i = 0; i < NUM_VALUES; i++)
    {
        values[i] = (float)rand() / RAND_MAX;
    }

    // calculate the mean value of the sequence
    float sum = 0.0;
    for (int i = 0; i < NUM_VALUES; i++)
    {
        sum += values[i];
    }
    float mean = sum / NUM_VALUES;

    // print out the mean value
    printf("The mean value of the random sequence is: %.6f\n", mean);

    return 0;
}