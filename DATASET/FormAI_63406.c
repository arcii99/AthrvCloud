//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

/* This program takes user input for two integers, adds them together, and then multiplies them by 10 */

int main()
{
    int num1, num2, sum, product;

    printf("Please enter the first integer: ");
    scanf("%d", &num1);

    printf("Please enter the second integer: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    product = sum * 10;
    printf("If we multiply the sum by 10 we get: %d\n", product);

    return 0;
}