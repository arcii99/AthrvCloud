//FormAI DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate memory for 5 integers
    int* ptr = (int*) malloc(5 * sizeof(int));

    // Check if memory was successfully allocated
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Print memory address of allocated block
    printf("Block of memory allocated at %p\n", ptr);

    // Initialize values in allocated memory
    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;
    ptr[3] = 40;
    ptr[4] = 50;

    // Print values in allocated memory
    printf("Values in allocated memory:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Deallocate memory
    free(ptr);

    printf("Memory deallocated\n");

    return 0;
}