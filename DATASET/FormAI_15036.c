//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complete
#include <stdio.h>

int fib(int n);

int main()
{
    int n, i;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Check if the user has entered a valid integer for the number of terms
    if (n <= 0)
    {
        printf("The number of terms must be a positive integer.\n");
        return 0;
    }

    // Display the Fibonacci sequence
    printf("Fibonacci sequence for %d terms:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", fib(i));
    }
    printf("\n");

    return 0;
}

// Fibonacci sequence recursive function
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fib(n-1) + fib(n-2);
    }
}