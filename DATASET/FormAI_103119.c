//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // configurable array size

int sum(int* arr, int size) {
    int result = 0;
    for(int i = 0; i < size; i++) {
        result += arr[i];
    }
    return result;
}

int main() {
    srand(time(NULL));
    int* arr = malloc(ARRAY_SIZE * sizeof(int)); // dynamically allocate array

    // initialize array with random integers between 1 and 100
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }

    clock_t start = clock(); // start timer
    int result = sum(arr, ARRAY_SIZE); // perform computation
    clock_t end = clock(); // end timer

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // calculate time taken
    printf("Sum: %d\n", result);
    printf("Time taken: %f seconds\n", time_taken);

    free(arr); // free allocated memory
    return 0;
}