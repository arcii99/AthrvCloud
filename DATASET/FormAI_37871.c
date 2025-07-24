//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// A function that sorts an integer array using Bubble Sort algorithm
void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i;
    int arr[ARRAY_SIZE];

    // Initialize random seed
    srand(time(0));

    // Fill the array with random integers between 1 and 100
    for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // Print the unsorted array
    printf("Unsorted Array:\n");
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using Bubble Sort
    bubbleSort(arr, ARRAY_SIZE);

    // Print the sorted array
    printf("Sorted Array:\n");
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}