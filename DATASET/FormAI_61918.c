//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: irregular
#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;

    else if (n == 1)
        return 1;

    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n, i, j, k=1;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i=1; i<=n; i++)
    {
        for (j=1; j<=i; j++)
        {
            printf("%d", fibonacci(k));
            k++;
        }
        printf("\n");
    }

    return 0;
}