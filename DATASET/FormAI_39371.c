//FormAI DATASET v1.0 Category: Benchmarking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double my_function();

int main()
{
    clock_t start_time, end_time;
    double total_time;

    start_time = clock();

    my_function();

    end_time = clock();

    total_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    printf("Total time taken: %f seconds.\n", total_time);

    return 0;
}

double my_function()
{
    double x = 0;
    for (int i = 0; i < 10000000; i++)
    {
        x = x + i;
    }
    return x;
}