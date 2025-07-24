//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>

#define SIZE 10000000

int main()
{
    // Allocate memory dynamically
    int* arr = (int*)malloc(sizeof(int) * SIZE);

    // Fill array with random values
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand();
    }

    // Perform bubble sort
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print sorted array
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(arr);

    return 0;
}