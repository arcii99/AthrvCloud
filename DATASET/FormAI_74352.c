//FormAI DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_RUNS 10000  // Number of times to run the benchmark

int main() {
    // Initialize variables
    int n = 100000;  // Length of the array
    int* arr = (int*) malloc(sizeof(int) * n);
    int i, j, temp;
    clock_t start, end;
    double total_time;

    // Fill the array with random numbers between 0 and 99
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Bubble Sort Benchmark
    start = clock();
    for (i = 0; i < NUM_RUNS; i++) {
        for (j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();
    total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort:\t%f seconds\n", total_time);

    // Quick Sort Benchmark
    start = clock();
    for (i = 0; i < NUM_RUNS; i++) {
        quick_sort(arr, 0, n - 1);
    }
    end = clock();
    total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort:\t%f seconds\n", total_time);

    // Insertion Sort Benchmark
    start = clock();
    for (i = 0; i < NUM_RUNS; i++) {
        insertion_sort(arr, n);
    }
    end = clock();
    total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort:\t%f seconds\n", total_time);

    free(arr);  // Free the memory allocated for arr
    return 0;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int temp;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}