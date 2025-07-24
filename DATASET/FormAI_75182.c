//FormAI DATASET v1.0 Category: Benchmarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000 // Size of array to be sorted

int cmpfunc (const void * a, const void * b) { // Comparison function required for qsort
   return ( *(int*)a - *(int*)b );
}

int main() {
    int i;
    clock_t start, end;
    double cpu_time_used;

    // Initialize array with random values between 1 to 1000
    int arr[SIZE];
    for(i=0; i<SIZE; i++){
        arr[i] = rand()%1000 + 1;
    }

    // Record starting time
    start = clock();

    // Sort array using qsort
    qsort(arr, SIZE, sizeof(int), cmpfunc);

    // Record ending time
    end = clock();

    // Calculate time elapsed
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f\n", cpu_time_used);

    return 0;
}