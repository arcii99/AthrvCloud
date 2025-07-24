//FormAI DATASET v1.0 Category: Memory management ; Style: retro
#include <stdlib.h>
#include <stdio.h>

int main(void) {

    //allocate memory for 10 integers
    int *ptr = (int*)malloc(10 * sizeof(int));

    //check if memory allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //initialize values in the allocated memory
    for (int i = 0; i < 10; i++) {
        *(ptr+i) = i * 2;
    }

    //print the initialized values
    printf("Values in the allocated memory:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr+i));
    }

    //reallocate memory for 20 integers
    ptr = (int*)realloc(ptr, 20 * sizeof(int));

    //check if reallocation was successful
    if (ptr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    //initialize new values in the reallocated memory
    for (int i = 10; i < 20; i++) {
        *(ptr+i) = i * 3;
    }

    //print the initialized values in the reallocated memory
    printf("\nValues in the reallocated memory:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", *(ptr+i));
    }

    //free the allocated memory
    free(ptr);
    printf("\nMemory has been freed.\n");

    return 0;
}