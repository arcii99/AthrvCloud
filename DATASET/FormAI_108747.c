//FormAI DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <time.h>

#define NUM_ITERATIONS 1000000

int main() {
    printf("Starting Benchmarking Program...\n");

    clock_t start, end;
    double time_taken;

    // Timer for loop increment operation
    start = clock();
    int counter = 0;
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        counter++;
    }
    end = clock();
    time_taken = (double)(end - start) / (double)CLOCKS_PER_SEC;
    printf("Loop increment operation took %f seconds.\n", time_taken);

    // Timer for multiplication operation
    start = clock();
    int product = 1;
    for (int i = 1; i <= NUM_ITERATIONS; i++) {
        product *= i;
    }
    end = clock();
    time_taken = (double)(end - start) / (double)CLOCKS_PER_SEC;
    printf("Multiplication operation took %f seconds.\n", time_taken);

    // Timer for division operation
    start = clock();
    double result = 3.0 / 4.0;
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        result = result / 2.0;
    }
    end = clock();
    time_taken = (double)(end - start) / (double)CLOCKS_PER_SEC;
    printf("Division operation took %f seconds.\n", time_taken);

    printf("Program Complete.\n");

    return 0;
}