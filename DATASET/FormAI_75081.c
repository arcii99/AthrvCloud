//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: synchronous
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("\n");
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fib[i]);
        for (int j = 0; j < fib[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}