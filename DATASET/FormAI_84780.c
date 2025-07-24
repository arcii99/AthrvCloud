//FormAI DATASET v1.0 Category: Benchmarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOOP_COUNT 10000000

int main()
{
    clock_t start, end;
    double cpu_time_used;
    int i, j;
    int *array = malloc(sizeof(int) * LOOP_COUNT);

    srand(time(NULL));

    // set random values for the array
    for(i = 0; i < LOOP_COUNT; i++)
    {
        array[i] = rand() % 100;
    }

    // Test 1: Loop through the array randomly
    start = clock();
    for(i = 0; i < LOOP_COUNT; i++)
    {
        j = rand() % LOOP_COUNT;
        array[j] *= 2;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Test 1: %.2f seconds\n", cpu_time_used);

    // Test 2: Loop through the array sequentially
    start = clock();
    for(i = 0; i < LOOP_COUNT; i++)
    {
        array[i] *= 2;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Test 2: %.2f seconds\n", cpu_time_used);

    free(array);

    return 0;
}