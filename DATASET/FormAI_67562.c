//FormAI DATASET v1.0 Category: Benchmarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int main()
{
    int i, j, temp, arr[SIZE];
    clock_t start, end;

    srand(time(NULL));  // Seed random number generator

    //Filling array with random integers from 1 to 100
    printf("Generating random array...\n");
    for (i = 0; i < SIZE; i++)
        arr[i] = rand() % 100 + 1;

    //Sorting array using Bubble Sort Algorithm
    printf("Sorting array using Bubble Sort...\n");
    start = clock();
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();

    //Displaying sorted array
    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    //Calculating time taken for Bubble Sort Algorithm
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nBubble Sort Algorithm took %f seconds to execute", time_taken);

    return 0;
}