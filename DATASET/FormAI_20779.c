//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

/* Function prototype */
double average(int arr[], int n);

int main()
{
    int i, arr[ARRAY_SIZE];
    double result;
    clock_t start, end;

    /* Fill the array with random numbers */
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 101;
    }

    /* Benchmark the function */
    start = clock();
    result = average(arr, ARRAY_SIZE);
    end = clock();

    /* Print the result and time */
    printf("The average of the array is: %f\n", result);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/* Function definition */
double average(int arr[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return (double)sum / n;
}