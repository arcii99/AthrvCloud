//FormAI DATASET v1.0 Category: Calculator ; Style: portable
#include <stdio.h>

int main() {
    printf("#############################################################\n\n");
    printf("Welcome to the Portable Calculator! \n");
    printf("This calculator can perform basic arithmetic operations on two numbers. \n");
    printf("Enter the operation you would like to perform (e.g. +, -, *, /): ");
    
    char operator;
    scanf("%c", &operator);
    
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
        printf("\nEnter the first number: ");
        double num1;
        scanf("%lf", &num1);
        
        printf("Enter the second number: ");
        double num2;
        scanf("%lf", &num2);
        
        double result;
        if (operator == '+') {
            result = num1 + num2;
            printf("\nThe sum of %lf and %lf is %lf.", num1, num2, result);
        } else if (operator == '-') {
            result = num1 - num2;
            printf("\nThe difference between %lf and %lf is %lf.", num1, num2, result);
        } else if (operator == '*') {
            result = num1 * num2;
            printf("\nThe product of %lf and %lf is %lf.", num1, num2, result);
        } else {
            if (num2 == 0) {
                printf("\nError: Cannot divide by zero.");
                return 0;
            } else {
                result = num1 / num2;
                printf("\nThe quotient of %lf and %lf is %lf.", num1, num2, result);
            }
        }
        
    } else {
        printf("\nError: Invalid operator.");
    }
    
    printf("\n\nThank you for using the Portable Calculator!");
    printf("\n#############################################################\n");
    return 0;
}