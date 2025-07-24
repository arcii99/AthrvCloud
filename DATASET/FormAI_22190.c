//FormAI DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000 // size of array to be sorted
#define MAX_VALUE 1000 // maximum value of array elements

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selection_sort(int arr[], int n) {
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

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[SIZE], i;
    clock_t start, end;
    double cpu_time_used;

    // generate random array of size SIZE and maximum value MAX_VALUE
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    // sort array using bubble sort and measure time
    start = clock();
    bubble_sort(arr, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: Time taken = %f seconds\n", cpu_time_used);

    // re-generate random array
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    // sort array using selection sort and measure time
    start = clock();
    selection_sort(arr, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: Time taken = %f seconds\n", cpu_time_used);

    // re-generate random array
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    // sort array using insertion sort and measure time
    start = clock();
    insertion_sort(arr, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort: Time taken = %f seconds\n", cpu_time_used);

    return 0;
}