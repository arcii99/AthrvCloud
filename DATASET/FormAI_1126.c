//FormAI DATASET v1.0 Category: Scientific ; Style: beginner-friendly
#include <stdio.h>

// function to calculate the factorial of a given number
int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// function to calculate the power of a given number
int power(int base, int exponent)
{
    int result = 1;
    for (int i = 1; i <= exponent; i++)
    {
        result *= base;
    }
    return result;
}

int main()
{
    int n, x;
    float sum = 0.0;

    // user input for the values of n and x
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of x: ");
    scanf("%d", &x);

    // calculating the series
    for (int i = 0; i <= n; i++)
    {
        sum += (float)power(-1, i) * power(x, 2 * i + 1) / factorial(2 * i + 1);
    }

    // printing the answer
    printf("The value of sin(%d) = %f", x, sum);

    return 0;
}