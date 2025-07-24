//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int i, j, temp;
    int arr[ARRAY_SIZE];

    // Fill the array with random integers
    srand(time(NULL)); // Seed the random number generator
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 1000; // Random integer between 0 and 999
    }

    // Perform bubble sort
    for(i = 0; i < ARRAY_SIZE - 1; i++)
    {
        for(j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print the sorted array
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}