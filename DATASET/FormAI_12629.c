//FormAI DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int *myArray;

    // Memory allocation
    myArray = (int *) malloc(MAX_SIZE * sizeof(int));
    if(myArray == NULL) {
        printf("Error: Unable to allocate memory\n");
        return 0;
    }

    // Initialize the array with random values
    for(int i = 0; i < MAX_SIZE; i++) {
        myArray[i] = rand();
    }

    // Print the array
    for(int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    // Reallocation of memory
    myArray = (int *) realloc(myArray, MAX_SIZE * sizeof(int) * 2);
    if(myArray == NULL) {
        printf("Error: Unable to reallocate memory\n");
        return 0;
    }

    // Initialize the newly allocated memory with random values
    for(int i = MAX_SIZE; i < MAX_SIZE*2; i++) {
        myArray[i] = rand();
    }

    // Print the updated array
    for(int i = 0; i < MAX_SIZE*2; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(myArray);

    return 0;
}