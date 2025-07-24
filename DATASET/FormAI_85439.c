//FormAI DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    
    printf("Welcome to the Arithmetic Program!\n");
    printf("Please input two numbers to perform arithmetic operations.\n");
    
    printf("Number 1: ");
    scanf("%d", &num1);
    
    printf("Number 2: ");
    scanf("%d", &num2);
    
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;
    
    printf("\nThank you! The result of the following arithmetic operations are: \n");
    
    printf("\n--------------------------------\n");
    printf("Sum: %d + %d = %d\n", num1, num2, sum);
    printf("Difference: %d - %d = %d\n", num1, num2, difference);
    printf("Product: %d * %d = %d\n", num1, num2, product);
    printf("Quotient: %d / %d = %d\n", num1, num2, quotient);
    printf("Remainder: %d %% %d = %d\n", num1, num2, remainder);
    printf("--------------------------------\n\n");

    printf("Thank you for using the Arithmetic Program!\n");
    printf("Hope you found it helpful.\n");
    
    return 0;
}