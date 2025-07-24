//FormAI DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int size;
    
    // Get the input size from the user
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    // Allocate memory dynamically to store the array
    array = (int*) malloc(size * sizeof(int));
    
    // Check if memory is allocated properly or not
    if(array == NULL) {
        printf("Memory allocation failed. Exiting...");
        return 0;
    }
    
    // Get the elements of array from the user
    for(int i = 0; i < size; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &array[i]);
    }
    
    // Display the elements of array
    printf("Array elements are:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    // Deallocate dynamically allocated memory
    free(array);
    
    return 0;
}