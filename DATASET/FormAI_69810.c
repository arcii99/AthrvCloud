//FormAI DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function for the benchmarking
void benchmark(int n) {
    int* arr = (int*)malloc(sizeof(int)*n);
    clock_t start, end;
    double cpu_time_used;
    
    // init array with random values
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
    
    // sort the array
    start = clock();
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    end = clock();

    // print result
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort an array of size %d: %f s\n", n, cpu_time_used);
}

int main() {
    printf("Starting benchmarking...\n");
    
    // run benchmark for different array sizes
    benchmark(100);
    benchmark(1000);
    benchmark(10000);
    
    printf("Done.\n");
    return 0;
}