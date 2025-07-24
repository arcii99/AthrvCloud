//FormAI DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to calculate the nth Fibonacci number using recursion
int fibonacci_recursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

// function to calculate the nth Fibonacci number using a loop
int fibonacci_iterative(int n)
{
    int a = 0, b = 1, i, temp;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++)
    {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// function to benchmark a function and print the execution time
double benchmark(int (*func)(int), int arg)
{
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    (*func)(arg);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

int main()
{
    int n = 40;
    double t1, t2;
    
    t1 = benchmark(fibonacci_recursive, n);
    t2 = benchmark(fibonacci_iterative, n);
    
    printf("Execution time of recursive Fibonacci: %f\n", t1);
    printf("Execution time of iterative Fibonacci: %f\n", t2);
    
    if (t1 < t2)
        printf("Recursive Fibonacci is faster.\n");
    else
        printf("Iterative Fibonacci is faster.\n");
    
    return 0;
}