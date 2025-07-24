//FormAI DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>

int factorial(int num)
{
    if(num == 1 || num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num-1);
    }
}

int fib(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        return fib(n-1) + fib(n-2);
    }
}

int main()
{
    int num;
    printf("Enter a number to find factorial: ");
    scanf("%d", &num);

    printf("Factorial of %d is: %d\n", num, factorial(num));

    int num1;
    printf("Enter a number to find Fibonacci: ");
    scanf("%d", &num1);

    printf("Fibonacci %d is: %d", num1, fib(num1));
    return 0;
}