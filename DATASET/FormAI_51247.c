//FormAI DATASET v1.0 Category: Benchmarking ; Style: ultraprecise
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;

    int num = 100000000;
    int sum = 0;

    start = clock(); // start the timer

    for (int i = 1; i <= num; i++)
        sum = sum + i; // calculate the sum of the numbers 1 to 100000000

    end = clock(); // end the timer
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate the time taken

    // display the results
    printf("Sum of numbers from 1 to %d is %d\n", num, sum);
    printf("Time taken to calculate the sum: %f seconds\n", cpu_time_used);

    return 0;
}