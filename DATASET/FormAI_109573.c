//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ken Thompson
#include <stdio.h>

// function prototype for fibonacci sequence
int fibonacci(int);

int main()
{
    int n, i;

    printf("Enter the number of terms in Fibonnaci sequence: ");
    scanf("%d", &n);

    // check for valid input
    while(n < 1)
    {
        printf("Invalid input! Please enter a positive integer.\n");
        scanf("%d", &n);
    }

    printf("\nFibonacci sequence for %d terms:\n", n);

    // create and print the Fibonacci sequence
    for(i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    return 0;
}

int fibonacci(int n)
{
    // base case
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    // recursive case
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}