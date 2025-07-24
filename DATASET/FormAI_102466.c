//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: decentralized
#include <stdio.h>

// Function to calculate nth Fibonacci number
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// Function to display the Fibonacci sequence visually
void printFibonacci(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            printf("%d", fibonacci(j));
            if(j < i)
                printf(" + ");
        }
        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter the value of n to display the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("\nThe Fibonacci sequence of %d numbers is:\n\n", n);
    printFibonacci(n);

    return 0;
}