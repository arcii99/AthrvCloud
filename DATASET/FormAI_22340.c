//FormAI DATASET v1.0 Category: Educational ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main()
{
    int num, result;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    if(num < 0)
    {
        printf("Error! Factorial of a negative number doesn't exist.");
        return EXIT_FAILURE;
    }
    result = factorial(num);
    printf("Factorial of %d = %d", num, result);
    return EXIT_SUCCESS;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}