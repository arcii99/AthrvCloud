//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5000000

// Function to initialize an array with random values
void init_array(int *arr) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        *(arr + i) = rand() % 100;
    }
}

// Function to print the contents of an array
void print_array(int *arr) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// Function to perform a bubble sort on an array
void bubble_sort(int *arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int *arr = (int *)malloc(SIZE * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    
    // Initialize the array with random values
    init_array(arr);
    
    // Print the unsorted array
    printf("Unsorted array:\n");
    print_array(arr);
    
    // Sort the array using bubble sort
    bubble_sort(arr);
    
    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr);
    
    // Free the memory allocated to the array
    free(arr);
    
    return 0;
}