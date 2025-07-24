//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A function that takes an array of integers and returns the sum of those integers */
int sum(int *arr, int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += arr[i];
    }
    return result;
}

/* The main function */
int main() {
    // Generate a random array of 10,000 integers
    int arr[10000];
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 100;
    }

    // Call the sum function and measure the time it takes
    clock_t start = clock();
    int result = sum(arr, 10000);
    clock_t end = clock();

    // Print the result and the time it took to compute it
    printf("The sum is %d\n", result);
    printf("Time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}