//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

int main() {
    // Allocate memory for a large array
    int* arr = (int*) malloc(SIZE * sizeof(int));
    if (!arr) {
        printf("Error: unable to allocate memory\n");
        return -1;
    }

    // Initialize array with random numbers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Sort array using bubble sort algorithm
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < SIZE - 1; i++) {
            if (arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sorted = 0;
            }
        }
    }

    // Display the sorted array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0;
}