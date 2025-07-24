//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: systematic
#include <stdio.h>

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

void fibPrint(int n)
{
    int i;
    printf("\nFibonacci Series upto %d terms : ", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", fib(i));
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of terms to display in Fibonacci series : ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("\nInvalid input!\n");
    }
    else
    {
        fibPrint(n);
    }

    return 0;
}