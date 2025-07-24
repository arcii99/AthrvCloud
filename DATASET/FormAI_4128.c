//FormAI DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int my_array[ARRAY_SIZE];
    double total = 0, run_time, avg_time;

    clock_t start, end;

    printf("Filling the array with random values...\n");

    srand(time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        my_array[i] = rand() % 1000;
    }

    printf("Starting the benchmark...\n");

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        start = clock();

        /* Add your benchmarking code here */

        end = clock();

        run_time = (double)(end - start) / CLOCKS_PER_SEC;
        total += run_time;

        printf("Iteration %d took %f seconds\n", i+1, run_time);
    }

    avg_time = total / ARRAY_SIZE;

    printf("The benchmark has finished!\n");
    printf("Average run time was %f seconds\n", avg_time);

    return 0;
}