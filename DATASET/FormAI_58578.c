//FormAI DATASET v1.0 Category: Benchmarking ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main(void) {
    clock_t start, end;
    double cpu_time_used;

    int *arr = malloc(sizeof(int) * ARRAY_SIZE);

    // Fill array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    // Benchmarking bubble sort
    start = clock();
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nBubble Sort:\nTime taken: %f seconds\n", cpu_time_used);

    // Benchmarking selection sort
    start = clock();
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nSelection Sort:\nTime taken: %f seconds\n", cpu_time_used);

    // Benchmarking insertion sort
    start = clock();
    for (int i = 1; i < ARRAY_SIZE; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nInsertion Sort:\nTime taken: %f seconds\n", cpu_time_used);

    // Free memory
    free(arr);

    return 0;
}