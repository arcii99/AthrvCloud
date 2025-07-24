//FormAI DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

double getTimeDifference(clock_t start, clock_t end)
{
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main(void)
{
    int* arr = (int*)malloc(sizeof(int) * ARRAY_SIZE);

    if (arr == NULL) {
        printf("Memory allocation failed!");
        return 0;
    }

    printf("Initializing array with random values...\n");

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    printf("Starting benchmark...\n");

    clock_t start, end;

    // Puzzle 1: Try to optimize this loop to be as fast as possible!
    start = clock();

    unsigned long long sum = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += arr[i];
    }

    end = clock();

    printf("Sum: %llu\n", sum);
    printf("Time taken for puzzle 1: %lf seconds\n", getTimeDifference(start, end));

    // Puzzle 2: Can you make this loop faster than the previous one?
    start = clock();

    sum = 0;

    for (int i = 0; i < ARRAY_SIZE; i += 2) {
        sum += arr[i];
    }

    for (int i = 1; i < ARRAY_SIZE; i += 2) {
        sum += arr[i];
    }

    end = clock();

    printf("Sum: %llu\n", sum);
    printf("Time taken for puzzle 2: %lf seconds\n", getTimeDifference(start, end));

    // Puzzle 3: This one's tricky - can you beat the previous two?
    start = clock();

    sum = 0;

    for (int i = 0; i < ARRAY_SIZE; i += 8) {
        sum += arr[i];
        sum += arr[i + 1];
        sum += arr[i + 2];
        sum += arr[i + 3];
        sum += arr[i + 4];
        sum += arr[i + 5];
        sum += arr[i + 6];
        sum += arr[i + 7];
    }

    end = clock();

    printf("Sum: %llu\n", sum);
    printf("Time taken for puzzle 3: %lf seconds\n", getTimeDifference(start, end));

    free(arr);

    return 0;
}