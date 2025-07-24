//FormAI DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[SIZE];
    clock_t start, end;
    double cpu_time_used;

    // Fill the array with random integers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % SIZE;
    }

    // Measure the time taken by the quicksort algorithm
    start = clock();
    qsort(arr, SIZE, sizeof(int), compare_int);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken by quicksort: %f seconds\n", cpu_time_used);
    return 0;
}