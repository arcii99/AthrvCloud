//FormAI DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main(void)
{
    int arr[SIZE];
    int i, j, temp;

    // Generate random array of integers
    srand(time(NULL));
    for(i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % SIZE;
    }

    // Bubble Sort algorithm
    for(i = 0; i < SIZE-1; i++)
    {
        for(j = 0; j < SIZE-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print sorted array
    printf("Sorted array:\n");
    for(i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}