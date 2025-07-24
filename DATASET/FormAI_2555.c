//FormAI DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LOOPS 1000000

int main()
{
    int i;
    clock_t start, end;
    double cpu_time_used;

    int* arr = (int*) malloc(sizeof(int) * NUM_LOOPS);

    // Initialize array
    for (i = 0; i < NUM_LOOPS; i++) {
        arr[i] = i + 1;
    }

    // Method 1: Loop through array and sum elements
    start = clock();
    int sum1 = 0;
    for (i = 0; i < NUM_LOOPS; i++) {
        sum1 += arr[i];
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Method 1: Sum of elements is %d and took %f seconds to execute.\n", sum1, cpu_time_used);

    // Method 2: Use pointer to loop through array and sum elements
    start = clock();
    int sum2 = 0;
    int* ptr = arr;
    for (i = 0; i < NUM_LOOPS; i++) {
        sum2 += *ptr;
        ptr++;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Method 2: Sum of elements is %d and took %f seconds to execute.\n", sum2, cpu_time_used);

    free(arr);

    return 0;
}