//FormAI DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {

    int array[MAX_SIZE];
    int sum = 0;
    clock_t t1, t2;
    double time_diff;

    // Generate random array
    for (int i = 0; i < MAX_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Benchmarking loop
    for (int i = 0; i < 10; i++) {
        t1 = clock();
        // Loop through the array and calculate the sum
        for (int j = 0; j < MAX_SIZE; j++) {
            sum += array[j];
        }
        t2 = clock();
        time_diff = ((double) t2 - t1) / CLOCKS_PER_SEC;
        printf("Iteration %d took %f seconds.\n", i + 1, time_diff);
    }

    return 0;
}