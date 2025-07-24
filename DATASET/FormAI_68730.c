//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function for Performance-Critical Component
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main()
{
    clock_t t1, t2;
    double cpu_time_used;

    int n = 40; // change the value of n to test different values

    t1 = clock();
    printf("Fibonacci number for n=%d is %d\n", n, fib(n));
    t2 = clock();

    cpu_time_used = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
    printf("Time taken by Fibonacci function for n=%d: %f seconds", n, cpu_time_used);

    return 0;
}