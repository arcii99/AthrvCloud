//FormAI DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUM_OF_ITERATIONS 1000000000

int main() {
    clock_t start_time, end_time;

    int num = 0;
    start_time = clock();
    for(int i = 0; i < NUM_OF_ITERATIONS; i++) {
        num += i;
    }
    end_time = clock();
    double result_1 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    float floatNum = 0.0;
    start_time = clock();
    for(int i = 0; i < NUM_OF_ITERATIONS; i++) {
        floatNum += i;
    }
    end_time = clock();
    double result_2 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    double doubleNum = 0.0;
    start_time = clock();
    for(int i = 0; i < NUM_OF_ITERATIONS; i++) {
        doubleNum += i;
    }
    end_time = clock();
    double result_3 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("%d iterations of integer addition took %f seconds.\n", NUM_OF_ITERATIONS, result_1);
    printf("%d iterations of float addition took %f seconds.\n", NUM_OF_ITERATIONS, result_2);
    printf("%d iterations of double addition took %f seconds.\n", NUM_OF_ITERATIONS, result_3);

    return 0;
}