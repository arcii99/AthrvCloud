//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program generates a random array of integers of size 10 million 
   and sorts the array using the bubble sort algorithm. */

#define ARRAY_SIZE 10000000

// Returns the current time in seconds
double getCurrentTimeInSeconds()
{
    return (double) clock() / CLOCKS_PER_SEC;
}

// Prints the given error message and exits the program
void exitWithError(char* errorMessage)
{
    printf("%s\n", errorMessage);
    exit(EXIT_FAILURE);
}

// Sorts the given array in ascending order using the bubble sort algorithm
void bubbleSort(int array[], int size)
{
    int i, j;
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // Generate a random array of integers
    srand(time(NULL));
    int array[ARRAY_SIZE];
    int i;
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand();
    }

    // Print some statistics about the unsorted array
    printf("Unsorted array:\n");
    printf("First element: %d\n", array[0]);
    printf("Last element: %d\n", array[ARRAY_SIZE - 1]);
    printf("Minimum value: %d\n", array[0]);
    printf("Maximum value: %d\n", array[0]);
    for(i = 1; i < ARRAY_SIZE; i++)
    {
        if(array[i] < array[0])
        {
            printf("Minimum value: %d\n", array[i]);
        }
        if(array[i] > array[ARRAY_SIZE - 1])
        {
            printf("Maximum value: %d\n", array[i]);
        }
    }

    // Sort the array using bubble sort
    double startTime = getCurrentTimeInSeconds();
    bubbleSort(array, ARRAY_SIZE);
    double endTime = getCurrentTimeInSeconds();

    // Print some statistics about the sorted array
    printf("Sorted array:\n");
    printf("First element: %d\n", array[0]);
    printf("Last element: %d\n", array[ARRAY_SIZE - 1]);
    printf("Minimum value: %d\n", array[0]);
    printf("Maximum value: %d\n", array[0]);
    for(i = 1; i < ARRAY_SIZE; i++)
    {
        if(array[i] < array[0])
        {
            printf("Minimum value: %d\n", array[i]);
        }
        if(array[i] > array[ARRAY_SIZE - 1])
        {
            printf("Maximum value: %d\n", array[i]);
        }
    }

    // Print some statistics about the sorting process
    printf("Sorting time: %.2f seconds\n", endTime - startTime);

    return 0;
}