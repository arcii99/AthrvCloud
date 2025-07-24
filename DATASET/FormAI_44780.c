//FormAI DATASET v1.0 Category: Benchmarking ; Style: futuristic
#include <stdio.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int arr[SIZE];
    long int sum = 0;
    clock_t start, end;
    double cpu_time_used;

    // initialize array elements with random numbers
    for(int i=0; i<SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // measure time for sequential array traversal
    start = clock();
    for(int i=0; i<SIZE; i++) {
        sum += arr[i];
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for sequential array traversal: %f seconds\n", cpu_time_used);

    // measure time for parallel array traversal
    sum = 0;
    start = clock();
    #pragma omp parallel for reduction(+:sum)
    for(int i=0; i<SIZE; i++) {
        sum += arr[i];
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for parallel array traversal: %f seconds\n", cpu_time_used);

    return 0;
}