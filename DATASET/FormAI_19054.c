//FormAI DATASET v1.0 Category: Benchmarking ; Style: future-proof
#include <stdio.h>
#include <time.h>

#define NUM_ITERATIONS 10000

int main(int argc, char *argv[]) {
    int arr[1000];

    /* Populate the array with random values */
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        arr[i] = rand();
    }
    
    /* Start the timer */
    clock_t start_time = clock();
    
    /* Perform the benchmarking iterations */
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        /* Example code: Find the sum of the array */
        int sum = 0;
        for (int j = 0; j < 1000; j++) {
            sum += arr[j];
        }
        
        /* Example code: Find the product of the array */
        long long product = 1;
        for (int j = 0; j < 1000; j++) {
            product *= arr[j];
        }
    }
    
    /* Calculate the total time taken and print the result */
    clock_t end_time = clock();
    double elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    printf("Benchmarking completed in %lf seconds\n", elapsed_time);
    
    return 0;
}