//FormAI DATASET v1.0 Category: Benchmarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000
#define MAX_TEST 100000000

int main() {
    int array[SIZE];
    srand((unsigned int)time(NULL));

    // initialize the array with random numbers
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand();
    }

    // benchmarking starts here
    clock_t start = clock();

    for (int i = 0; i < MAX_TEST; i++) {
        // write the benchmarking code here
        int sum = 0;
        for (int j = 0; j < SIZE; j++) {
            sum += array[j];
        }
    }

    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The benchmarking result: %lf\n", cpu_time_used);

    return 0;
}