//FormAI DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, sum, difference, product, quotient, remainder;

    // Getting user input for first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Getting user input for second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Find the Sum of Two Numbers
    sum = num1 + num2;
    printf("The sum of %d and %d is %d. \n", num1, num2, sum);

    // Find the Difference of Two Numbers
    difference = num1 - num2;
    printf("The difference between %d and %d is %d. \n", num1, num2, difference);

    // Find the Product of Two Numbers
    product = num1 * num2;
    printf("The product of %d and %d is %d. \n", num1, num2, product);

    // Find the Quotient and Remainder of Two Numbers
    quotient = num1 / num2;
    remainder = num1 % num2;
    printf("The quotient of %d and %d is %d.\n", num1, num2, quotient);
    printf("The remainder of %d and %d is %d.\n", num1, num2, remainder);

    printf("Wow! That was exciting. We just calculated the sum, difference, product, quotient and remainder of two numbers. \n");

    return 0;
}