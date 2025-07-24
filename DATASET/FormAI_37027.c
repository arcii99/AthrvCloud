//FormAI DATASET v1.0 Category: Benchmarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int main() {
    int arr[SIZE];
    clock_t start, end;
    double exec_time;
    
    // Fill array with random integers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }
    
    // Sort array using bubble sort algorithm
    start = clock();
    for (int i = 0; i < SIZE-1; i++) {
        for (int j = 0; j < SIZE-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    exec_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Execution Time: %f seconds\n", exec_time);
    
    
    // Sort array using quick sort algorithm
    start = clock();
    quick_sort(arr, 0, SIZE-1);
    end = clock();
    exec_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort Execution Time: %f seconds\n", exec_time);
    
    return 0;
}

void quick_sort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot-1);
        quick_sort(arr, pivot+1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    
    for (int j = left; j <= right-1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;
    return i+1;
}