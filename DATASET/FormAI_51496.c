//FormAI DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000 // number of elements in array

void selection_sort(int arr[], int n) {
    int i, j;
    int min_idx, temp;
  
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
  
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int i;
    clock_t start, end;
    double cpu_time_used;

    int arr1[N], arr2[N];
    for (i = 0; i < N; i++) {
        arr1[i] = rand() % 10000;
        arr2[i] = arr1[i];
    }

    // Selection Sort Benchmarking
    printf("======= Selection Sort Benchmarking =======\n");
    start = clock();
    selection_sort(arr1, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort Time: %f seconds\n", cpu_time_used);

    // Insertion Sort Benchmarking
    printf("\n======= Insertion Sort Benchmarking =======\n");
    start = clock();
    insertion_sort(arr2, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort Time: %f seconds\n", cpu_time_used);

    return 0;
}