//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

int main() {
    int array[ARRAY_SIZE];
    clock_t start, end;
    double cpu_time_used;

    // Initialize the array with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Bubble sort benchmarking
    start = clock();
    for (int i = ARRAY_SIZE - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort took %f seconds\n", cpu_time_used);

    // Merge sort benchmarking
    start = clock();
    merge_sort(array, 0, ARRAY_SIZE-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Merge sort took %f seconds\n", cpu_time_used);

    return 0;
}

void merge(int arr[], int left_start, int left_end, int right_start, int right_end) {
    int temp[right_end];
    int i = left_start, j = right_start, k = 0;
    while (i <= left_end && j <= right_end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= left_end) {
        temp[k++] = arr[i++];
    }

    while (j <= right_end) {
        temp[k++] = arr[j++];
    }

    for (i = left_start, k = 0; i <= right_end; i++, k++) {
        arr[i] = temp[k];
    }
}

void merge_sort(int arr[], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        merge_sort(arr, start, middle);
        merge_sort(arr, middle+1, end);
        merge(arr, start, middle, middle+1, end);
    }
}