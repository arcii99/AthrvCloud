//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int compare_int(const void *a, const void *b) {
    const int *ia = (const int *) a;
    const int *ib = (const int *) b;
    return *ia - *ib;
}

int main() {
    
    // Introspective benchmarking
    clock_t start, end;
    double time_used;
    start = clock();

    // Generate an array of random numbers
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Sort the array using qsort
    qsort(arr, SIZE, sizeof(int), compare_int);

    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d integers: %f seconds", SIZE, time_used);

    return 0;
}