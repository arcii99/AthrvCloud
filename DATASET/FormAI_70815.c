//FormAI DATASET v1.0 Category: Scientific ; Style: portable
#include <stdio.h>

// function prototype
double power(double base, int exponent);

int main(void)
{
    double base, result;
    int exponent;

    printf("Enter the base: ");
    scanf("%lf", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    // call the power function
    result = power(base, exponent);

    printf("%g to the power of %d is %g\n", base, exponent, result);

    return 0;
}

// function definition
double power(double base, int exponent) 
{
    double result = 1;

    while (exponent > 0) 
    {
        result *= base;
        exponent--;
    }

    return result;
}