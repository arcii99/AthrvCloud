//FormAI DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Generate an array of random integers
    int n = 100000;
    int arr[n];
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        arr[i] = rand();
    }

    // Calculate the sum of the array using for loop
    start = clock();
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for for loop: %f seconds\n", cpu_time_used);

    // Reset sum to zero
    sum = 0;

    // Calculate the sum of the array using while loop
    start = clock();
    int i = 0;
    while(i < n) {
        sum += arr[i];
        i++;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for while loop: %f seconds\n", cpu_time_used);

    // Reset sum to zero
    sum = 0;

    // Calculate the sum of the array using pointer arithmetic
    start = clock();
    int *ptr = arr;
    for(int i=0; i<n; i++) {
        sum += *(ptr+i);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for pointer arithmetic: %f seconds\n", cpu_time_used);

    return 0;
}