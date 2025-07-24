//FormAI DATASET v1.0 Category: Benchmarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

int main() {
    int arr[SIZE], i, j, temp;

    // Generate random numbers in array
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10000;
    }

    // Bubble sort benchmarking
    clock_t start_bubble = clock();
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    clock_t end_bubble = clock();
    double time_bubble = (double) (end_bubble - start_bubble) / CLOCKS_PER_SEC;
    printf("Bubble sort took %.10f seconds\n", time_bubble);

    // Quick sort benchmarking
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10000;
    }
    clock_t start_quick = clock();
    quickSort(arr, 0, SIZE - 1);
    clock_t end_quick = clock();
    double time_quick = (double) (end_quick - start_quick) / CLOCKS_PER_SEC;
    printf("Quick sort took %.10f seconds\n", time_quick);

    return 0;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}