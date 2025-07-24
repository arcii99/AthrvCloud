//FormAI DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int main() {
    double start, end;
    int arr[SIZE];
    int sum = 0;

    srand(time(NULL));

    // Generate random integers in array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    start = clock(); // Start time

    // Sum all elements in array
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    end = clock(); // End time

    printf("Sum of array: %d\n", sum);
    printf("Time taken: %f seconds\n", (end-start)/CLOCKS_PER_SEC);

    return 0;
}