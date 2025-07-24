//FormAI DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int i, j;
    clock_t start_time, end_time;
    double bubble_sort_time, selection_sort_time;

    // generate random array
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    // measure bubble sort time
    start_time = clock();
    bubble_sort(arr, ARRAY_SIZE);
    end_time = clock();
    bubble_sort_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    // measure selection sort time
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }
    start_time = clock();
    selection_sort(arr, ARRAY_SIZE);
    end_time = clock();
    selection_sort_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    // print results
    printf("Array size: %d\n", ARRAY_SIZE);
    printf("Bubble sort time: %f seconds\n", bubble_sort_time);
    printf("Selection sort time: %f seconds\n", selection_sort_time);

    return 0;
}