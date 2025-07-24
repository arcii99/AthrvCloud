//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: recursive
#include <stdio.h>

// This is an example of a recursive function that calculates
// the n-th number of the Fibonacci sequence.

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n = 10;
    printf("Fibonacci sequence up to %d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}