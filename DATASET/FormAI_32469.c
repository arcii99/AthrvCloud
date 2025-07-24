//FormAI DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100000 //Size of the array

int main()
{
    // Allocate memory for an array of integers
    int* arr = (int*)malloc(ARRAY_SIZE * sizeof(int));

    // Check if the allocation was successful
    if (arr == NULL)
    {
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    // Fill the array with random numbers
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 100;
    }

    // Print the sum of the array
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        sum += arr[i];
    }

    printf("Sum of array = %d\n", sum);

    // Deallocate the memory allocated for the array
    free(arr);

    return 0;
}