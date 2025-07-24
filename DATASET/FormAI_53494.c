//FormAI DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

// Function to fill an array with random numbers
void fillArray(int arr[]) {
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to use Selection Sort to sort an array
void selectionSort(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to use Quick Sort to sort an array
void quickSort(int arr[], int low, int high) {
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

        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[ARRAY_SIZE];

    // Fill array with random numbers
    fillArray(arr);

    // Benchmark Selection Sort
    printf("Benchmarking Selection Sort...\n");
    clock_t selection_start = clock();
    selectionSort(arr);
    clock_t selection_end = clock();
    double selection_time = (double)(selection_end - selection_start) / CLOCKS_PER_SEC;
    printf("\nSelection Sort Time: %f seconds", selection_time);

    // Fill array with another set of random numbers
    fillArray(arr);

    // Benchmark Quick Sort
    printf("\n\nBenchmarking Quick Sort...\n");
    clock_t quick_start = clock();
    quickSort(arr, 0, ARRAY_SIZE - 1);
    clock_t quick_end = clock();
    double quick_time = (double)(quick_end - quick_start) / CLOCKS_PER_SEC;
    printf("\nQuick Sort Time: %f seconds", quick_time);

    return 0;
}