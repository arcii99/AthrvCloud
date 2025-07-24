//FormAI DATASET v1.0 Category: Scientific ; Style: synchronous
#include<stdio.h>

// Function declaration
int factorial(int n);

int main()
{
    int num, fact;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Validation
    if(num < 0)
    {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 0;
    }

    else
    {
        fact = factorial(num);
        printf("The factorial of %d is %d\n", num, fact);
    }

    return 0;
}

// Function definition
int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;

    else
        return n * factorial(n-1);
}