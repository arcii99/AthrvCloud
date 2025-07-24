//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    double num1, num2, result;
    char operator;

    printf("Enter an operator (+, -, *, /, ^): ");
    scanf("%c", &operator); 

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch(operator) {

        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
            break;

        case '/':
            if(num2 == 0) {
                printf("Error: Cannot divide by zero");
                exit(0);
            } 
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
            break;

        case '^':
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf", num1, num2, result);
            break;

        default:
            printf("Error: Invalid operator");
            exit(0);

    }

    return 0;
}