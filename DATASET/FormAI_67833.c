//FormAI DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    clock_t start, end;
    double cpu_time_used;
    int n = 1000000;
    int *arr = (int*)malloc(n * sizeof(int));
    
    // Fill array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    
    // Bubble sort
    start = clock();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %lf seconds\n", cpu_time_used);
    
    // Quick Sort
    start = clock();
    quicksort(arr, 0, n-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort Time: %lf seconds\n", cpu_time_used);
    
    free(arr);
    
    return 0;
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high-1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}