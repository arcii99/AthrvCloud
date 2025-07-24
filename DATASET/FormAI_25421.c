//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: relaxed
#include <stdio.h>

void printFibonacci(int n);

int main()
{
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("\n");

    printFibonacci(n);

    return 0;
}

void printFibonacci(int n)
{
    int i, t1 = 0, t2 = 1, nextTerm;

    for (i = 1; i <= n; ++i)
    {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}