//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: decentralized
#include <stdio.h>

int fibonacci(int n);
void printFibonacciSeries(int n);

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series:\n");
    printFibonacciSeries(n);

    return 0;
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return (fibonacci(n-1) + fibonacci(n-2));
}

// Function to print the Fibonacci series up to n terms
void printFibonacciSeries(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", fibonacci(i));
    }
}