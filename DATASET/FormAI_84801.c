//FormAI DATASET v1.0 Category: Recursive ; Style: content
/* This program demonstrates the use of recursion in C programming language. 
   It calculates the factorial of a given number. */
#include <stdio.h>

// Recursive function definition
int factorial(int n)
{
    if (n == 0) // Base case
        return 1;
    else // Recursive case
        return n * factorial(n-1);
}

int main()
{
    int n, result;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Call the factorial function
    result = factorial(n);

    printf("The factorial of %d is %d\n", n, result);

    return 0;
}