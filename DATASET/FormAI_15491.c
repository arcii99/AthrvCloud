//FormAI DATASET v1.0 Category: Recursive ; Style: satisfied
#include <stdio.h>

int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n*factorial(n-1);
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n, choice, result;
    printf("Welcome to the Recursive Program!\n");
    printf("Please choose which function you want to use:\n");
    printf("1. Factorial\n2. Fibonacci\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    printf("Please enter a number: ");
    scanf("%d", &n);

    switch(choice)
    {
        case 1:
            result = factorial(n);
            printf("\nThe factorial of %d is %d\n", n, result);
            break;
        case 2:
            result = fibonacci(n);
            printf("\nThe %dth Fibonacci number is %d\n", n, result);
            break;
        default:
            printf("\nInvalid choice\n");
            break;
    }

    return 0;
}