//FormAI DATASET v1.0 Category: Sorting ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    int n = 10;
    int arr[n];

    printf("Unsorted Array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}