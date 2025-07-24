//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include <stdio.h>

void fibonacci(int n)
{
    int a = 0, b = 1, c = 0;
    printf("%d %d ", a, b); // print the first two terms of Fibonacci sequence

    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

int main()
{
    int n;
    printf("Enter the number of terms in Fibonacci sequence : ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}