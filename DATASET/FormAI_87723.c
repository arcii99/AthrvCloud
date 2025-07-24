//FormAI DATASET v1.0 Category: Calculator ; Style: beginner-friendly
#include <stdio.h>

int main() {
    char operator;
    double num1, num2;
    
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    
    switch (operator) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf", num1, num2, num1 + num2);
            break;
        
        case '-':
            printf("%.2lf - %.2lf = %.2lf", num1, num2, num1 - num2);
            break;
        
        case '*':
            printf("%.2lf * %.2lf = %.2lf", num1, num2, num1 * num2);
            break;
        
        case '/':
            if (num2 == 0) {
                printf("Division by zero is undefined");
            } else {
                printf("%.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
            }
            break;
        
        default:
            printf("Invalid operator");
    }
    
    return 0;
}