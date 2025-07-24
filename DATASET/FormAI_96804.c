//FormAI DATASET v1.0 Category: Benchmarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
    int i, j, tmp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx, tmp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int n = 10000;
    int arr[n], i;
    clock_t t;
    double time_taken;
    
    // fill array with random values
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
    
    // measure bubble sort time
    t = clock();
    bubble_sort(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds\n", time_taken);
    
    // measure selection sort time
    srand(time(NULL));  // reset seed to get different array
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
    t = clock();
    selection_sort(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Selection Sort took %f seconds\n", time_taken);
    
    // measure insertion sort time
    srand(time(NULL));  // reset seed again
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
    t = clock();
    insertion_sort(arr, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %f seconds\n", time_taken);
    
    return 0;
}