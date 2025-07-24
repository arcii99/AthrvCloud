//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <time.h>

int main() {
    int i, j, sum = 0;
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (i = 0; i < 1000000; i++) {
        for (j = 0; j < 100; j++) {
            sum++;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sum: %d \n", sum);
    printf("Time taken: %lf seconds. \n", cpu_time_used);

    return 0;
}