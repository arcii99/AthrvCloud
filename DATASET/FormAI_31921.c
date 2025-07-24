//FormAI DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
    // allocate memory for 10 integers
    int *ptr = (int*) malloc(10 * sizeof(int));

    // check if allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // initialize the array with random values
    for (int i = 0; i < 10; i++) {
        ptr[i] = rand();
    }

    // print the array
    printf("Array Contents: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }

    // release the memory
    free(ptr);

    // allocate memory for 5 doubles
    double *dptr = (double*) calloc(5, sizeof(double));

    // check if allocation was successful
    if (dptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // initialize the array with random values
    for (int i = 0; i < 5; i++) {
        dptr[i] = (double) rand() / RAND_MAX;
    }

    // print the array
    printf("\nDouble Array Contents: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", dptr[i]);
    }

    // resize the array to hold 10 doubles
    double *newdptr = (double*) realloc(dptr, 10 * sizeof(double));

    // check if reallocation was successful
    if (newdptr == NULL) {
        printf("\nMemory reallocation failed\n");
        free(dptr); // free the original array
        return 1;
    }

    // add more random values to the array
    for (int i = 5; i < 10; i++) {
        newdptr[i] = (double) rand() / RAND_MAX;
    }

    // print the resized array
    printf("\nResized Array Contents: ");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", newdptr[i]);
    }

    // release the memory
    free(newdptr);

    return 0;
}