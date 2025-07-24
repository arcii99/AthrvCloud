//FormAI DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>

int fibonacci(int n)
{
    if (n < 2)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n = 10;
    printf("Fibonacci sequence up to %d:\n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    printf("\n");
    
    return 0;
}