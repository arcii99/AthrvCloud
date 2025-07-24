//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: artistic
#include <stdio.h>
#include <time.h>

#define SIZE 100000

// Returns the sum of all elements in the given array
int calculateSum(int arr[]) {
    int sum = 0;
    for(int i = 0; i < SIZE; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[SIZE];
    srand(time(NULL));

    // Fill array with random numbers
    for(int i = 0; i < SIZE; ++i) {
        arr[i] = rand();
    }

    // Calculate sum of array and time it
    clock_t startTime = clock();
    int sum = calculateSum(arr);
    clock_t endTime = clock();

    // Print results
    printf("Array size: %d\n", SIZE);
    printf("Sum of array: %d\n", sum);
    printf("Time taken: %f seconds\n", ((double) (endTime - startTime)) / CLOCKS_PER_SEC);

    return 0;
}