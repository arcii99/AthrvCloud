//FormAI DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

int main()
{
    int arr[ARRAY_SIZE];
    int i, j, temp;

    // Initialize array with random numbers
    srand(time(NULL));
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Start benchmarking clock
    clock_t start = clock();

    // Sort array using selection sort algorithm
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        int min = i;
        for(j = i+1; j < ARRAY_SIZE; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    // Stop benchmarking clock
    clock_t end = clock();

    // Calculate elapsed time and print benchmarking results
    double elapsed_time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}