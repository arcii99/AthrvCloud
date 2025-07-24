//FormAI DATASET v1.0 Category: Benchmarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Holy cow, I can't believe I'm doing C benchmarking!\n");
    clock_t start, end;
    double cpu_time_used;
    int n = 5000000, i;
    int *arr;

    printf("Allocating memory for the array...\n");
    arr = (int*) malloc(n * sizeof(int));

    printf("Initializing the array with random numbers...\n");
    for (i = 0; i < n; i++)
        arr[i] = rand();

    printf("Starting the timer...\n");
    start = clock();

    printf("Sorting the array using Bubble Sort...\n");
    int temp;
    for (i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Stopping the timer...\n");
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time used for sorting: %f seconds\n", cpu_time_used);

    printf("Deallocating memory...\n");
    free(arr);

    return 0;
}