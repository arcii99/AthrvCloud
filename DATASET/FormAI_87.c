//FormAI DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* array;
    int size, i;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    // Allocate memory dynamically
    array = (int*) malloc(size * sizeof(int));
    
    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }
    
    // Initialize array with random values
    for (i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    
    // Print the values in the array
    printf("Values in the array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    // Free up the memory
    free(array);
    
    return 0;
}