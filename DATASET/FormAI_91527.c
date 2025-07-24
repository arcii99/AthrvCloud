//FormAI DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

void fillArray(int array[]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }
}

double runTest(int array[]) {
    clock_t start, end;
    double total_time;
    start = clock();

    // Code to be benchmarked
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    end = clock();
    total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    return total_time;
}

int main() {
    int array[SIZE];
    fillArray(array);

    printf("Starting benchmarking!\n\n");

    double time1 = runTest(array);
    printf("Test 1 completed in %f seconds.\n", time1);

    // Code optimization
    for (int i = 0; i < SIZE; i++) {
        array[i] *= 2;
    }

    double time2 = runTest(array);
    printf("Test 2 completed in %f seconds.\n", time2);

    printf("\nBenchmarking completed successfully!\n");
    return 0;
}