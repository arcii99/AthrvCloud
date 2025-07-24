//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n, i;
    printf("Enter the length of Fibonacci sequence: ");
    scanf("%d", &n);
    printf("\n");
    for (i = 0; i < n; i++) {
        int num = fibonacci(i);
        printf("|");
        for (int j = 0; j < num; j++) {
            printf("*");
        }
        printf("|\n");
    }
    return 0;
}