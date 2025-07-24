//FormAI DATASET v1.0 Category: Calculator ; Style: peaceful
#include <stdio.h>

int main() {
    printf("Welcome to the Peaceful Calculator\n");
    printf("Here, we don't divide people, we divide numbers.\n");
    printf("Please enter a mathematical expression to calculate:\n");
    
    char operator;
    double num1, num2, result;
    scanf("%lf %c %lf", &num1, &operator, &num2);
    
    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
        case '/':
            if(num2 == 0) {
                printf("We cannot divide by zero in this peaceful world!\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
            }
            break;
        default:
            printf("Invalid operator. Please try again with a valid operator.\n");
    }
    
    printf("Thank you for using the Peaceful Calculator. Let's keep the peace and love on.\n");
    return 0;
}