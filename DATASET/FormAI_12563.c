//FormAI DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int arr_size = 10000000;
    int *arr = (int*)malloc(arr_size * sizeof(int));

    // Initialize array with random elements
    srand(time(NULL));
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand();
    }

    // Start the timer
    clock_t start = clock();

    // Find the max element in the array
    int max = arr[0];
    for (int i = 1; i < arr_size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // End the timer and calculate the runtime
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Max Element in Array: %d\n", max);
    printf("Time taken by the program: %f seconds", time_taken);

    free(arr);
    return 0;
}