//FormAI DATASET v1.0 Category: Benchmarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[ARRAY_SIZE], i;

    // Generate random array
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % ARRAY_SIZE;
    }

    // Test bubble sort
    clock_t start = clock();
    bubbleSort(arr, ARRAY_SIZE);
    clock_t end = clock();
    printf("Time taken for bubble sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Test selection sort
    start = clock();
    selectionSort(arr, ARRAY_SIZE);
    end = clock();
    printf("Time taken for selection sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Test insertion sort
    start = clock();
    insertionSort(arr, ARRAY_SIZE);
    end = clock();
    printf("Time taken for insertion sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}