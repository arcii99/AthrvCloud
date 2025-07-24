//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: random
#include <stdio.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int array[ARRAY_SIZE];
    int i, j;
    int temp;
    int swaps;

    // Initialize array with random numbers
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand() % ARRAY_SIZE;
    }

    // Bubble sort algorithm 
    for (i = 0; i < ARRAY_SIZE - 1; i++)
    {
        swaps = 0;
        for (j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swaps++;
            }
        }
        if (swaps == 0)
        {
            break;
        }
    }

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}