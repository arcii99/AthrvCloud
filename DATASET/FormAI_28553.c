//FormAI DATASET v1.0 Category: Recursive ; Style: random
#include <stdio.h>

/* This recursive function returns the nth number in the Fibonacci sequence. */
int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n-1) + fib(n-2);
    }
}

int main()
{
    int n = 10;
    printf("The %dth number in the Fibonacci sequence is %d\n", n, fib(n));
    return 0;
}