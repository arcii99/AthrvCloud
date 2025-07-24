//FormAI DATASET v1.0 Category: Benchmarking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the function to be timed
int calculate_sum(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
    int array[100000];
    int size = 100000;

    // Populate the array with random numbers
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }

    clock_t start, end;
    double cpu_time_used;

    // Calculate the time taken for the function to execute
    start = clock();
    int sum = calculate_sum(array, size);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The sum of the array is %d.\n", sum);
    printf("The function took %f seconds to execute.\n", cpu_time_used);

    return 0;
}