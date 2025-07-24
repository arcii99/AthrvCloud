//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void print_array(int *arr, int n) {
    printf("[ ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("]\n");
}

int main() {
    // Allocate memory for an integer array of size 10
    int *arr = (int *) malloc(SIZE * sizeof(int));
    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Error: Unable to allocate memory.\n");
        return -1;
    }

    printf("Enter 10 integers:\n");
    for (int i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);

    printf("Array before sorting:\n");
    print_array(arr, SIZE);

    // Sort the array using bubble sort algorithm
    for (int i = 0; i < SIZE-1; i++) {
        for (int j = 0; j < SIZE-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Array after sorting:\n");
    print_array(arr, SIZE);

    // Deallocate the memory
    free(arr);

    return 0;
}