//FormAI DATASET v1.0 Category: Benchmarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int arr[ARRAY_SIZE];
    int i, j;
    clock_t start, end;
    double duration;

    // Fill the array with random integers between 0 and 99
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 100;
    }

    // Record the starting time
    start = clock();

    // Bubble sort algorithm
    for(i = 0; i < ARRAY_SIZE - 1; i++)
    {
        for(j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Record the ending time
    end = clock();

    // Calculate the duration
    duration = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array:\n");
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the duration
    printf("Duration: %f seconds\n", duration);

    return 0;
}