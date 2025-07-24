//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int main()
{
    int i, j, temp;
    int arr[SIZE];

    // Fill the array with random integers
    srand(time(NULL));
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Show the original array
    printf("Original array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
        if (i % 10 == 9) printf("\n");
    }

    // Bubble sort
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

    // Show the sorted array
    printf("\nSorted array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
        if (i % 10 == 9) printf("\n");
    }

    return 0;
}