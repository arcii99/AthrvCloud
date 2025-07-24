//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: satisfied
#include <stdio.h>

void generateFib(int n)
{
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("The Fibonacci sequence up to %d is: \n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", fib[i]);
    }
}

int main()
{
    int n;

    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &n);

    generateFib(n);

    return 0;
}