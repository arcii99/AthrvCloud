//FormAI DATASET v1.0 Category: Benchmarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000

int main(void)
{
    clock_t start, end;
    double cpu_time_used;

    int *arr = (int*) malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        arr[i] = rand();

    start = clock();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken = %f\n", cpu_time_used);

    free(arr);

    return 0;
}