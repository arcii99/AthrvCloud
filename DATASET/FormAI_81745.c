//FormAI DATASET v1.0 Category: Benchmarking ; Style: immersive
#include <stdio.h>
#include <time.h>

int main() {
    printf("Welcome to the Benchmarking program!\n");

    // Initializing variables
    int n = 1000000;
    int arr[n];
    clock_t start, end;
    double cpu_time_used;

    // Initializing array with random values
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

    // Bubble sort implementation
    start = clock();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for Bubble sort: %f seconds\n", cpu_time_used);

    // Quick sort implementation
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for Quick sort: %f seconds\n", cpu_time_used);

    return 0;
}

// Quick sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Partition function for quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}