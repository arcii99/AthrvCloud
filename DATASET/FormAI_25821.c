//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

// Function to swap values in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform quicksort on an array
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i+1], &arr[high]);

        quicksort(arr, low, i);
        quicksort(arr, i+2, high);
    }
}

int main() {
    int array[ARRAY_SIZE];

    // Generate random numbers for array
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % ARRAY_SIZE;
    }

    // Sort the array using quicksort
    quicksort(array, 0, ARRAY_SIZE-1);

    // Print the sorted array
    printf("Sorted Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}