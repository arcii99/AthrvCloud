//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

double seconds_diff(struct timespec start, struct timespec end) {
    return (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    int *arr;
    arr = (int *)malloc(sizeof(int) * ARRAY_SIZE);

    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }

    struct timespec start, end;
    double naive_time, optimized_time;

    // naive implementation
    clock_gettime(CLOCK_MONOTONIC, &start);
    long sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += arr[i];
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    naive_time = seconds_diff(start, end);

    // optimized implementation
    clock_gettime(CLOCK_MONOTONIC, &start);
    long optimized_sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i += 8) {
        optimized_sum += arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3] + arr[i + 4] + arr[i + 5] + arr[i + 6] + arr[i + 7];
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    optimized_time = seconds_diff(start, end);

    printf("Naive implementation time: %f s\n", naive_time);
    printf("Optimized implementation time: %f s\n", optimized_time);

    free(arr);
    return 0;
}