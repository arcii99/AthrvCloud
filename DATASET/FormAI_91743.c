//FormAI DATASET v1.0 Category: Math exercise ; Style: artistic
#include <stdio.h>

int main()
{
    int number1, number2, sum, difference, product, quotient, remainder;
    
    printf("Enter the first number: ");
    scanf("%d", &number1);
    printf("Enter the second number: ");
    scanf("%d", &number2);
    
    // calculation of sum
    sum = number1 + number2;
    printf("\nSum of the two numbers is: %d\n", sum);
    
    // calculation of difference
    difference = number1 - number2;
    printf("\nDifference of the two numbers is: %d\n", difference);
    
    // calculation of product
    product = number1 * number2;
    printf("\nProduct of the two numbers is: %d\n", product);
    
    // calculation of quotient
    quotient = number1 / number2;
    printf("\nQuotient of the two numbers is: %d\n", quotient);
    
    // calculation of remainder
    remainder = number1 % number2;
    printf("\nRemainder of the two numbers is: %d\n", remainder);
    
    // display the result
    printf("\n%d + %d = %d", number1, number2, sum);
    printf("\n%d - %d = %d", number1, number2, difference);
    printf("\n%d * %d = %d", number1, number2, product);
    printf("\n%d / %d = %d", number1, number2, quotient);
    printf("\n%d %% %d = %d\n", number1, number2, remainder);
    
    return 0;
}