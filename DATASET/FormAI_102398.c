//FormAI DATASET v1.0 Category: Benchmarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return (fibonacci(n-1) + fibonacci(n-2));
}

int main()
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    int n = 30; // change the value to change fibonacci term to be calculated
    
    printf("Fibonacci term %d is %d\n", n, fibonacci(n));
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}