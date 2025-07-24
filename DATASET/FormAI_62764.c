//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Romeo and Juliet
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
    int n, i, j;
    printf("How many numbers in the Fibonacci sequence would you like to see?\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        int current = fibonacci(i);
        for (j = 0; j < current; j++)
        {
            if (j % 2 == 0) 
            {
                printf("Romeo: %d\n", fibonacci(j));
            }
            else 
            {
                printf("Juliet: %d\n", fibonacci(j));
            }
        }
    }
    printf("The End.\n");
    return 0;
}