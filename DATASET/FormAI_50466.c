//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void initialize_array(int array[], int size)
{
    // Initialize array with random values
    srand(time(NULL));
    for(int i = 0; i< size; i++)
    {
        array[i] = rand() % 1000;
    }
}

void bubble_sort(int array[], int size)
{
    // Sort array in ascending order using bubble sort algorithm
    for(int i = 0; i< size-1; i++)
    {
        for(int j = 0; j< size-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int array[size];

    initialize_array(array, size);

    bubble_sort(array, size);

    printf("Sorted Array:");
    for(int i = 0; i< size; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}