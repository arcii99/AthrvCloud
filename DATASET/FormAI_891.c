//FormAI DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main() {
    clock_t start, end;
    double cpu_time_used;

    int array[N];
    int sum = 0;
    int i;
    
    // initialize array with random values
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        array[i] = rand() % 100;
    }

    // benchmarking starts here
    start = clock();

    // perform operation on array
    for (i = 0; i < N; i++) {
        sum += array[i];
    }
    
    // benchmarking ends here
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sum of array: %d\n", sum);
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}