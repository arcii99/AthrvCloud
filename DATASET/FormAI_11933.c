//FormAI DATASET v1.0 Category: Benchmarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[100000];
    clock_t start, end;
    double cpu_time_used;

    // Populate the array with random integers
    for (int i = 0; i < 100000; i++) {
        arr[i] = rand() % 100;
    }

    // Bubble Sort
    start = clock();
    for (int i = 0; i < 99999; i++) {
        for (int j = 0; j < 99999-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort time taken: %f seconds\n", cpu_time_used);

    // Insertion Sort
    start = clock();
    for (int i = 1; i < 100000; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort time taken: %f seconds\n", cpu_time_used);

    // Selection Sort
    start = clock();
    for (int i = 0; i < 100000 - 1; i++) {
        int min_index = i;
        for (int j = i+1; j < 100000; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort time taken: %f seconds\n", cpu_time_used);

    return 0;
}