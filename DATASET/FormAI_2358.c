//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000000

int main()
{
    int *array = malloc(sizeof(int) * ARRAY_SIZE);

    // Error checking for malloc
    if (array == NULL)
    {
        fprintf(stderr, "Error: Could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the array
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = i + 1;
    }

    // Calculate the sum of the array
    long long sum = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        sum += array[i];
    }

    // Print the sum
    printf("Sum of array: %lld", sum);

    free(array);

    return 0;
}