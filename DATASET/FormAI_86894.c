//FormAI DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int *ptr = NULL;

    // Allocating memory
    ptr = (int*)malloc(MAX_SIZE * sizeof(int));

    // Checking if allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return -1; // exit program with error code
    }

    // Initialization
    for (int i = 0; i < MAX_SIZE; i++) {
        ptr[i] = i+1;
    }

    // Printing out values
    printf("Values in allocated memory: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Re-allocating memory
    ptr = (int*)realloc(ptr, MAX_SIZE * 2 * sizeof(int));

    // Checking if re-allocation was successful
    if (ptr == NULL) {
        printf("Memory reallocation failed!\n");
        return -1; // exit program with error code
    }

    // Initialization of new values
    for (int i = MAX_SIZE; i < MAX_SIZE*2; i++) {
        ptr[i] = (i+1)*2;
    }

    // Printing out new values
    printf("Values in re-allocated memory: ");
    for (int i = 0; i < MAX_SIZE*2; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Freeing memory
    free(ptr);
    ptr = NULL;

    return 0; // exit program successfully
}