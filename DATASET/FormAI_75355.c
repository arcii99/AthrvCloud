//FormAI DATASET v1.0 Category: Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

/* Linus Torvalds-style code example */

/* The following function computes the factorial of a given integer n */
int factorial(int n)
{
    int i, fact = 1;

    if (n == 0)
        return 1;
    else
    {
        for (i = 1; i <= n; i++)
            fact *= i;
        return fact;
    }
}

int main()
{
    int n, i;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Error: Invalid input! Exiting program...\n");
        exit(0);
    }

    printf("Factorial of %d is: %d\n", n, factorial(n));

    /* The following code generates a Fibonacci series up to n terms */
    int a = 0, b = 1, c;
    printf("\nFibonacci series up to %d terms:\n", n);
    for (i = 1; i <= n; i++)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}