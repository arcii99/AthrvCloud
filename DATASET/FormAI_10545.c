//FormAI DATASET v1.0 Category: Sorting ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

// Function prototypes
void quicksort(int array[], int left, int right);
int partition(int array[], int left, int right);

int main() {
    int array[ARRAY_SIZE];
    srand(time(NULL)); // Seed the random number generator

    // Fill the array with random integers between 0 and 99
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Print out the unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Sort the array using quicksort
    quicksort(array, 0, ARRAY_SIZE - 1);

    // Print out the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

// Quicksort implementation
void quicksort(int array[], int left, int right) {
    if (left < right) {
        int pivot = partition(array, left, right);
        quicksort(array, left, pivot - 1);
        quicksort(array, pivot + 1, right);
    }
}

// Partition function used by quicksort
int partition(int array[], int left, int right) {
    int pivot = array[right]; // Choose the rightmost element as the pivot
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            // Swap array[i] and array[j]
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // Swap array[i+1] and array[right]
    int temp = array[i+1];
    array[i+1] = array[right];
    array[right] = temp;

    return i + 1;
}