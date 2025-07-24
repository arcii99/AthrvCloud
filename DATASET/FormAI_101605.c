//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000000

int main(void) {
    int nums[MAX_ARRAY_SIZE];
    int i;
    clock_t start, end;
    double cpu_time_used;

    // populate array with random integers between 0 and 100
    srand(time(NULL));
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        nums[i] = rand() % 100;
    }

    // sum array while measuring execution time
    start = clock();
    int sum = 0;
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        sum += nums[i];
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // print sum and execution time
    printf("Sum: %d\n", sum);
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}