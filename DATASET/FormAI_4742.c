//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 1000

// A performance-critical component that sorts an array of integers in ascending order using quicksort algorithm
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        quicksort(arr, low, i);
        quicksort(arr, i + 2, high);
    }
}

int main() {
    int arr[ARR_SIZE];

    // fill the array with random integer values
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    printf("Unsorted array:\n");
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    quicksort(arr, 0, ARR_SIZE - 1);

    printf("\n\nSorted array:\n");
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}