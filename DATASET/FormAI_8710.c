//FormAI DATASET v1.0 Category: Benchmarking ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 1000000

void swap(int *a, int *b) {
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
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int i;
    clock_t start, end;
    double time_used;

    srand(time(NULL));  
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    start = clock();
    bubbleSort(arr, ARRAY_SIZE);
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %f Seconds\n", time_used);

    start = clock();
    selectionSort(arr, ARRAY_SIZE);
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort Time: %f Seconds\n", time_used);

    start = clock();
    insertionSort(arr, ARRAY_SIZE);
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort Time: %f Seconds\n", time_used);

    return 0;
}