//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <time.h>

#define SIZE 1000000

int main()
{
    clock_t start, end;
    double cpu_time_used;

    int array[SIZE];

    // Fill array with random numbers
    for (int i = 0; i < SIZE; ++i)
    {
        array[i] = rand() % 1000;
    }

    // Testing loop that iterates through the array and sums up all the values
    start = clock();
    int sum = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        sum += array[i];
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("The sum of all elements in the array is: %d\n", sum);
    printf("Time taken to compute sum using loop: %f seconds\n", cpu_time_used);

    // Testing loop that iterates through the array and calculates the average value
    start = clock();
    double avg = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        avg += array[i];
    }
    avg /= SIZE;
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("The average of all elements in the array is: %f\n", avg);
    printf("Time taken to compute average using loop: %f seconds\n", cpu_time_used);

    // Testing loop that iterates through the array and finds the max value
    start = clock();
    int max = array[0];
    for (int i = 1; i < SIZE; ++i)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("The maximum value in the array is: %d\n", max);
    printf("Time taken to find max using loop: %f seconds\n", cpu_time_used);

    // Testing loop that iterates through the array and finds the min value
    start = clock();
    int min = array[0];
    for (int i = 1; i < SIZE; ++i)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("The minimum value in the array is: %d\n", min);
    printf("Time taken to find min using loop: %f seconds\n", cpu_time_used);

    return 0;
}