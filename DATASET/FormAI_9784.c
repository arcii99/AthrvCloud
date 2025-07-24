//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array
#define ARRAY_SIZE 1000000

// Define the maximum value for the random numbers
#define MAX_VALUE 100

// The performance-critical function to find the minimum value in an array
int find_minimum_value(int* array, int size)
{
    int minimum_value = MAX_VALUE;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < minimum_value)
        {
            minimum_value = array[i];
        }
    }
    return minimum_value;
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Populate the array with random numbers between 0 and MAX_VALUE
    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand() % MAX_VALUE;
    }

    // Call the performance-critical function to find the minimum value
    int minimum_value = find_minimum_value(array, ARRAY_SIZE);

    // Print the result
    printf("The minimum value in the array is: %d\n", minimum_value);

    return 0;
}