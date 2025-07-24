//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: recursive
#include <stdio.h>

// Recursive function to calculate the power of a number
int power(int base, int exponent)
{
    if (exponent == 0) {
        return 1;
    }
    else {
        return base * power(base, exponent - 1);
    }
}

// Recursive function to calculate the factorial of a number
int factorial(int n)
{
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

// Recursive function to calculate the sum of a series
float seriesSum(float x, int n)
{
    if (n == 0) {
        return 1;
    }
    else {
        return power(-1, n) * power(x, 2*n) / factorial(2*n) + seriesSum(x, n - 1);
    }
}

int main()
{
    int base = 2;
    int exponent = 4;
    int result = power(base, exponent);
    printf("%d ^ %d = %d\n", base, exponent, result);

    int n = 5;
    int fact = factorial(n);
    printf("%d! = %d\n", n, fact);

    float x = 3.14;
    int terms = 5;
    float sum = seriesSum(x, terms);
    printf("sin(%f) = %f\n", x, sum);

    return 0;
}