//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main() {
    int array[N];
    int sum = 0;

    // Generate random values for array
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        array[i] = rand() % 10;
    }

    // Calculate sum of array values
    clock_t start_time = clock();
    for (int i = 0; i < N; i++) {
        sum += array[i];
    }
    clock_t end_time = clock();

    // Display results
    printf("Sum of array values: %d\n", sum);
    printf("Time taken: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}