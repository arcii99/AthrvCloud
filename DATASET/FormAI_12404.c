//FormAI DATASET v1.0 Category: Benchmarking ; Style: romantic
#include <stdio.h>
#include <time.h>

void myFunction() {

    int sum = 0;

    for (int i = 0; i < 1000000; i++) {
        sum += i;
    }
}

int main() {

    clock_t start, end;
    double cpu_time_used;
    int iterations = 100;

    for (int i = 0; i < iterations; i++) {
        start = clock();
        myFunction();
        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Iteration %d: %f seconds\n", i, cpu_time_used);
    }

    double avg_time = cpu_time_used / iterations;
    printf("Average time taken: %f seconds", avg_time);

    return 0;
}