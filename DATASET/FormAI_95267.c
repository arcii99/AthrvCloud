//FormAI DATASET v1.0 Category: Arithmetic ; Style: calm
/*
 * Description: This program takes in two integers from the user and 
 * performs various arithmetic operations on them. The result of each
 * operation is displayed using printf statements.
 */

#include <stdio.h>

int main()
{
    int num1, num2, sum, diff, product, quotient, remainder;
    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    sum = num1 + num2;
    diff = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;
    
    printf("\nResults:\n");
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference between %d and %d is %d\n", num1, num2, diff);
    printf("The product of %d and %d is %d\n", num1, num2, product);
    printf("The quotient when %d is divided by %d is %d\n", num1, num2, quotient);
    printf("The remainder when %d is divided by %d is %d\n", num1, num2, remainder);
    
    return 0;
}