//FormAI DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function to allocate and initialize integer array
int *initializeArray(int size) {
    int *arr;
    arr = (int *) malloc(size * sizeof(int)); // Dynamically allocate memory for the array
    if (arr == NULL) { // Check if memory allocation was successful
        printf("Error: failed to allocate memory for array.");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1; // Initialize each element of the array with a unique value
    }
    return arr;
}

// Function to print the array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function that uses the above functions
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int *arr = initializeArray(size); // Call the function to initialize the array
    
    printf("The initialized array is: ");
    printArray(arr, size); // Call the function to print the array
    
    free(arr); // Free the dynamically allocated memory
    return 0;
}