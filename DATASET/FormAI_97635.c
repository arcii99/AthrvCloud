//FormAI DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr;

    // Allocating memory dynamically using malloc() function
    ptr = (int*) malloc(sizeof(int) * 5);

    // Checking if memory allocation is successful or not
    if (ptr == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    else 
    {
        printf("Memory allocation successful\n");
    }

    // Putting element values
    ptr[0] = 1;
    ptr[1] = 5;
    ptr[2] = 10;
    ptr[3] = 15;
    ptr[4] = 20;

    // Printing array values using pointer arithmetic
    printf("\nArray elements: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", *(ptr+i));
    }

    // Reallocating memory using realloc() function
    ptr = (int*) realloc(ptr, sizeof(int) * 8);

    // Checking if memory reallocation is successful or not
    if (ptr == NULL) 
    {
        printf("\nMemory reallocation failed\n");
        exit(1);
    }
    else 
    {
        printf("\nMemory reallocation successful\n");
    }

    // Putting new element values
    ptr[5] = 25;
    ptr[6] = 30;
    ptr[7] = 35;

    // Printing array values including the new element values
    printf("\nNew array elements: ");
    for(int i = 0; i < 8; i++)
    {
        printf("%d ", *(ptr+i));
    }

    // Freeing the dynamically allocated memory using free() function
    free(ptr);
    
    printf("\nMemory freed successfully\n");

    return 0;
}