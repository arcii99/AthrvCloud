//FormAI DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>

int main() {
    
    int num1, num2, sum, difference, product, quotient, remainder;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;
    
    printf("\nSum: %d + %d = %d", num1, num2, sum);
    printf("\nDifference: %d - %d = %d", num1, num2, difference);
    printf("\nProduct: %d * %d = %d", num1, num2, product);
    printf("\nQuotient: %d / %d = %d", num1, num2, quotient);
    printf("\nRemainder: %d %% %d = %d", num1, num2, remainder);
    
    return 0;
}