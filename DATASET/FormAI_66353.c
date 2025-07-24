//FormAI DATASET v1.0 Category: Benchmarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOOP_SIZE 100000000

int main()
{
    clock_t start, end;
    double cpu_time_used;
    int i, sum = 0;
    start = clock();

    // loop with addition
    for (i = 1; i <= LOOP_SIZE; i++) {
        sum += i;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Loop with addition took %f seconds to execute\n", cpu_time_used);

    start = clock();

    // loop with multiplication
    sum = 0;
    for (i = 1; i <= LOOP_SIZE; i++) {
        sum += i * i;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Loop with multiplication took %f seconds to execute\n", cpu_time_used);

    return 0;
}