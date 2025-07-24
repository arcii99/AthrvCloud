//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000000

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int i;
    int arr[ARRAY_SIZE];

    // Generate random values for array
    srand(0);
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 10000;
    }

    // Sort the array using insertion sort
    insertion_sort(arr, ARRAY_SIZE);

    // Print sorted array (for verification)
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}