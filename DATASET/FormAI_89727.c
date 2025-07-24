//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>
int main()
{
    int n, i, fib[50];

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // First two terms of Fibonacci sequence
    fib[0] = 0;
    fib[1] = 1;

    // Generating the remaining terms
    for (i = 2; i <= n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("The Fibonacci sequence of %d terms is:\n", n);

    // Printing the sequence
    for (i = 0; i < n; i++)
    {
        printf("%d\n", fib[i]);
    }

    return 0;
}