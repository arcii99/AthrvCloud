//FormAI DATASET v1.0 Category: Math exercise ; Style: recursive
#include <stdio.h>

int factorial(int n);

int main()
{
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Factorial of %d = %d\n", n, factorial(n));

    return 0;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}