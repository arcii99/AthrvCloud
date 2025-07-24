//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    int n = 100000;
    int arr[n];

    // Initialize the array with random integers
    for(int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    start = clock();

    // Sort the array using Bubble Sort algorithm
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    end = clock();

    // Calculate the time taken to sort the array
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d integers using Bubble Sort algorithm: %f seconds\n", n, cpu_time_used);

    return 0;
}