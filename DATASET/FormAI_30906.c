//FormAI DATASET v1.0 Category: Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {
    char operation;
    double num1, num2;

    printf("Welcome to the calculator program\n");
    printf("Please enter the operation you want to perform (+, -, *, /): ");
    scanf("%c", &operation);
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch(operation) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1+num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1-num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1*num2);
            break;
        case '/':
            if(num2 != 0) {
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1/num2);
            }
            else {
                printf("Error: Cannot divide by zero\n");
            }
            break;
        default:
            printf("Error: Invalid operation selected\n");
    }

    return 0;
}