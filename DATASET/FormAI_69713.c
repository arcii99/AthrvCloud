//FormAI DATASET v1.0 Category: Scientific ; Style: recursive
#include <stdio.h>

/* This program demonstrates a recursive function that finds the Fibonacci sequence at a specified index */

int fibonacci(int n);

int main()
{
    int n;

    printf("Please enter an index to find the corresponding Fibonacci number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input. The index must be a non-negative integer.\n");
        return 1;
    }

    printf("The Fibonacci number at index %d is: %d\n", n, fibonacci(n));

    return 0;
}

int fibonacci(int n)
{   
    if (n <= 1)
        return n;   /* base case */
    else
        return fibonacci(n-1) + fibonacci(n-2);   /* recursive case */
}