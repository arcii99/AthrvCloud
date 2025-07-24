//FormAI DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    printf("\nStarting benchmarking program...\n");

    // Declare and initialize variables
    int i, sum = 0;
    int array[ARRAY_SIZE];
    clock_t start, end;
    double cpu_time_used;

    // Generate random array
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Perform benchmark for for-loop
    printf("\nStarting for-loop benchmark...\n");
    start = clock();
    for (i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("For-loop sum: %d\n", sum);
    printf("For-loop CPU time used: %f seconds\n", cpu_time_used);

    // Perform benchmark for while-loop
    sum = 0;    // Reset sum variable
    printf("\nStarting while-loop benchmark...\n");
    start = clock();
    i = 0;
    while (i < ARRAY_SIZE) {
        sum += array[i];
        i++;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("While-loop sum: %d\n", sum);
    printf("While-loop CPU time used: %f seconds\n", cpu_time_used);

    // Perform benchmark for do-while-loop
    sum = 0;    // Reset sum variable
    printf("\nStarting do-while-loop benchmark...\n");
    start = clock();
    i = 0;
    do {
        sum += array[i];
        i++;
    } while (i < ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Do-while-loop sum: %d\n", sum);
    printf("Do-while-loop CPU time used: %f seconds\n", cpu_time_used);

    printf("\nBenchmarking program complete.\n");

    return 0;
}