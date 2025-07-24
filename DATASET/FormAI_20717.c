//FormAI DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {

    // Declare variables
    int i, j, temp;
    clock_t start, end;
    double cpu_time_used;
    int arr[SIZE];

    // Populate array with random values
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Perform benchmarking for Bubble Sort algorithm
    printf("Bubble Sort Benchmarking : \n");
    start = clock();
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken : %f seconds \n", cpu_time_used);

    // Reset array with random values
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Perform benchmarking for Selection Sort algorithm
    printf("Selection Sort Benchmarking : \n");
    start = clock();
    for (i = 0; i < SIZE - 1; i++) {
        int min_index = i;
        for (j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap elements
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken : %f seconds \n", cpu_time_used);

    return 0;
}