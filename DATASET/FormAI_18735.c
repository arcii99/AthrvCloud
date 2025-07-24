//FormAI DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* myArray = (int*) malloc(10 * sizeof(int)); // allocate 10 spaces in memory for an integer array
    if (myArray == NULL) { // check if allocation was successful
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < 10; i++) { // assign some values to the array
        myArray[i] = i * i;
    }

    printf("Array values:\n");
    for (int i = 0; i < 10; i++) { // output array values
        printf("%d ", myArray[i]);
    }
    printf("\n");

    myArray = (int*) realloc(myArray, 20 * sizeof(int)); // resize array to accommodate more values
    if (myArray == NULL) { // check if reallocation was successful
        printf("Error: Memory reallocation failed\n");
        exit(1);
    }

    for (int i = 10; i < 20; i++) { // assign some values to the newly resized array
        myArray[i] = i * i * i;
    }

    printf("New array values:\n");
    for (int i = 0; i < 20; i++) { // output values of resized array
        printf("%d ", myArray[i]);
    }
    printf("\n");

    free(myArray); // free the allocated memory
    printf("Memory has been freed successfully!\n");

    return 0;
}