//FormAI DATASET v1.0 Category: Benchmarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    clock_t start, end;
    double cpu_time_used;

    int size = 1000000;
    int *arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    start = clock();
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sum: %d\n", sum);
    printf("Time taken: %f seconds\n", cpu_time_used);

    free(arr);
    return 0;
}