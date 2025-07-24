//FormAI DATASET v1.0 Category: Recursive ; Style: ultraprecise
#include <stdio.h>

int fibonacci(int n);

int main()
{
    int limit, i;
    printf("Enter the limit for Fibonacci series: ");
    scanf("%d", &limit);
    printf("Fibonacci Series up to %d terms:\n", limit);
    for (i = 0; i < limit; i++)
    {
        printf("%d ", fibonacci(i));
    }
    return 0;
}

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}