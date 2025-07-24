//FormAI DATASET v1.0 Category: Recursive ; Style: calm
#include <stdio.h>

int fib(int n);

int main()
{
    int n, i;
    printf("\nEnter value of n: ");
    scanf("%d", &n);
    printf("\nFibonacci Series: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", fib(i));
    }
    return 0;
}

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}