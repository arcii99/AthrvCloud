//FormAI DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void init_array(int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % ARRAY_SIZE;
    }
}

void bubble_sort(int *arr) {
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int *arr) {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int arr[ARRAY_SIZE];

    init_array(arr);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    bubble_sort(arr);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort CPU time used: %f seconds\n", cpu_time_used);

    init_array(arr);

    start = clock();
    selection_sort(arr);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}