//FormAI DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Let's allocate memory dynamically using malloc for an integer array.
    int *intPtr = (int*)malloc(5 * sizeof(int)); // allocate memory for 5 integers
    if(intPtr == NULL) // check if allocation successful or not
    {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }

    // Now let's store some integers in the allocated memory.
    *intPtr = 10;
    *(intPtr + 1) = 20;
    *(intPtr + 2) = 30;
    *(intPtr + 3) = 40;
    *(intPtr + 4) = 50;

    // printing stored integers
    printf("Stored integers: ");
    for(int i=0; i<5; i++)
    {
        printf("%d ", *(intPtr + i));
    }

    // let's change the size of the allocated memory using realloc.
    intPtr = (int*)realloc(intPtr, 8 * sizeof(int)); // allocate memory for 8 integers
    if(intPtr == NULL) // check if allocation successful or not
    {
        printf("Error: Failed to reallocate memory.\n");
        exit(1);
    }

    // Now we can store more integers in the newly allocated memory.
    *(intPtr + 5) = 60;
    *(intPtr + 6) = 70;
    *(intPtr + 7) = 80;

    // printing all stored integers
    printf("\nNew Stored integers: ");
    for(int i=0; i<8; i++)
    {
        printf("%d ", *(intPtr + i));
    }

    // freeing allocated memory to avoid memory leaks.
    free(intPtr);
    intPtr = NULL;

    return 0;
}