//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: active
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n)
{
    int i, t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci Series: ");

    for (i = 1; i <= n; ++i)
    {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}

int main()
{
    int n;
    printf("\nEnter the number of terms: ");
    scanf("%d", &n);
    printFibonacci(n);
    return 0;
}