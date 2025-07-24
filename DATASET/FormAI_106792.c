//FormAI DATASET v1.0 Category: Sorting ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array
#define SIZE 100

int main()
{
    int arr[SIZE];
    int i, j, temp;

    // Generate random numbers and store them in the array
    srand(time(NULL));
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Print original array
    printf("Original Array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using bubble sort
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print sorted array
    printf("Sorted Array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}