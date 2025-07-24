//FormAI DATASET v1.0 Category: Benchmarking ; Style: Cryptic
#include <stdio.h>
#include <time.h>

#define MAX_NUMBER 1000000

int main() {
    clock_t start, end;
    double cpu_time_used;
    int i, j;
    long int sum = 0;

    printf("Benchmarking...\n\n");

    start = clock();

    for (i = 0; i < MAX_NUMBER; i++) {
        sum = 0;
        for (j = 0; j < i; j++) {
            sum += j;
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Result: %ld\n", sum);
    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}