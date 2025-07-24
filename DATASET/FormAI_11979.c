//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMUM 1000000
#define ITERATIONS 1000000
#define MINIMUM 0

double benchmark_math()
{
    double result = 0.0;

    for (int i = MINIMUM; i < MAXIMUM; i++)
    {
        result = rand() * rand() / ((double)RAND_MAX);
        result = result * result;
        result = result * i;
    }

    return result;
}

double benchmark_array()
{
    int array[MAXIMUM];
    int sum = 0;

    for (int j = 0; j < ITERATIONS; j++)
    {
        for (int i = MINIMUM; i < MAXIMUM; i++)
        {
            array[i] = 2 * i;
            sum += array[i];
        }
    }

    return sum;
}

int main()
{
    printf("Math Benchmark: %.2lf\n", benchmark_math());
    printf("Array Benchmark: %d\n", benchmark_array());
    return 0;
}