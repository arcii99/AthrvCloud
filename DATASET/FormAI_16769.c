//FormAI DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    // Declare variables
    int arr[MAX_SIZE];
    int i, j, temp;
    clock_t start, end;
    double cpu_time_used;

    // Fill array with random integers
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    // Start timer
    start = clock();

    // Bubble sort algorithm
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Stop timer
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print sorted array and time taken
    printf("Sorted array: ");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nCPU time used: %f seconds\n", cpu_time_used);

    return 0;
}