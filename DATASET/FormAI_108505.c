//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: thoughtful
#include <stdio.h>

// Function to calculate Fibonacci sequence for n terms
void fibonacci(int n)
{
    int i, first = 0, second = 1, next;
    printf("Fibonacci Sequence:\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }
}

// Function to draw Fibonacci sequence as a shape
void drawFibonacci(int n)
{
    int i, first = 0, second = 1, next, space = 5;
    printf("\n\nFibonacci Shape:\n\n");
    for (i = 1; i <= n; i++)
    {
        next = first + second;
        first = second;
        second = next;
        for (int j = 1; j <= space; j++)
        {
            printf(" ");
        }
        space -= 2;
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", next);
        }
        printf("\n");
    }
}

// Driver code
int main()
{
    int n;
    printf("Enter the number of terms for Fibonacci sequence:\n");
    scanf("%d", &n);
    fibonacci(n);
    drawFibonacci(n);
    return 0;
}