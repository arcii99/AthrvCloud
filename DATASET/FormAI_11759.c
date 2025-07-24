//FormAI DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int *arr, sum = 0, min = 1000000, max = 0;
    clock_t start, end;

    // allocate memory for array
    arr = (int*)malloc(ARRAY_SIZE * sizeof(int));

    // fill array with random numbers between 0 and 999
    srand(time(NULL));
    for(int i = 0; i < ARRAY_SIZE; i++) {
        *(arr+i) = rand() % 1000;
    }

    // Benchmarking: calculate sum, min, max of array
    start = clock();
    for(int i = 0; i < ARRAY_SIZE; i++) {
        sum += *(arr+i);

        if(*(arr+i) < min) {
            min = *(arr+i);
        }

        if(*(arr+i) > max) {
            max = *(arr+i);
        }
    }
    end = clock();

    // print results and time taken to calculate them
    printf("Sum of Array: %d\n", sum);
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // free allocated memory
    free(arr);

    return 0;
}