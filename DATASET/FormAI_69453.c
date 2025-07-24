//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
/* 
In this program, we will showcase the process of memory management in C language by dynamically allocating memory for an integer array,
printing its values, reallocating the memory and freeing it at the end.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 5; //default size of the integer array
    int* ptr = malloc(size * sizeof(int)); //dynamically allocate memory for the array

    //check if the memory allocation was successful
    if (ptr == NULL)
    {
        printf("Memory allocation failed!");
        return 0;
    }

    //print the values of the array
    printf("Values of the original array:\n");
    for (int i = 0; i < size; i++)
    {
        *(ptr + i) = i + 1;
        printf("%d ", *(ptr + i));
    }

    //reallocate the memory for the array to increase its size
    size = 10;
    ptr = realloc(ptr, size * sizeof(int));

    //check if the memory allocation was successful
    if (ptr == NULL)
    {
        printf("\nMemory reallocation failed!");
        return 0;
    }

    //print the values of the array after reallocation
    printf("\nValues of the reallocated array:\n");
    for (int i = 0; i < size; i++)
    {
        *(ptr + i) = i + 1;
        printf("%d ", *(ptr + i));
    }

    //free the dynamically allocated memory at the end
    free(ptr);

    //check for memory leak or errors using valgrind tool
    return 0;
}