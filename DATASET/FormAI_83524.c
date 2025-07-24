//FormAI DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Dynamically allocating memory for an array of integers
    int *array = (int*)malloc(5 * sizeof(int));
    
    if(array == NULL)
    {
        printf("Error: Not enough memory\n");
        exit(1);
    }

    // Assigning values to the array
    for(int i=0; i<5; i++)
    {
        array[i] = i+1;
    }

    // Printing the values of the array
    for(int i=0; i<5; i++)
    {
        printf("%d\n", array[i]);
    }

    // Reallocating memory for the array of integers
    array = (int*)realloc(array, 10 * sizeof(int));

    if(array == NULL)
    {
        printf("Error: Not enough memory\n");
        exit(1);
    }

    // Adding more values to the array
    for(int i=5; i<10; i++)
    {
        array[i] = i+1;
    }

    // Printing the values of the expanded array
    for(int i=0; i<10; i++)
    {
        printf("%d\n", array[i]);
    }

    // Freeing the allocated memory
    free(array);

    return 0;
}