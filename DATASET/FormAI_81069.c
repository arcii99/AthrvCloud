//FormAI DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++) 
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void generateRandomArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

int main() {
    clock_t t;
    int arr[ARRAY_SIZE];
    generateRandomArray(arr, ARRAY_SIZE);

    printf("Unsorted Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Benchmark selection sort
    t = clock();
    selectionSort(arr, ARRAY_SIZE);
    t = clock() - t;
    double selectionSortTime = ((double)t) / CLOCKS_PER_SEC;

    printf("Array sorted with Selection Sort:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nSelection Sort time taken: %f seconds\n", selectionSortTime);

    generateRandomArray(arr, ARRAY_SIZE);

    // Benchmark bubble sort
    t = clock();
    bubbleSort(arr, ARRAY_SIZE);
    t = clock() - t; 
    double bubbleSortTime = ((double)t) / CLOCKS_PER_SEC;

    printf("Array sorted with Bubble Sort:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nBubble Sort time taken: %f seconds\n", bubbleSortTime);

    return 0;
}