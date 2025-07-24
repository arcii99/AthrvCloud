//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>

int fibonacci(int n);

int main()
{
    int n, i;

    // Input number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Print Fibonacci sequence
    printf("Fibonacci sequence: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    return 0;
}

// Function to calculate Fibonacci number recursively
int fibonacci(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}