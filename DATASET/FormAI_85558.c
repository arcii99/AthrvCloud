//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: automated
#include <stdio.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Welcome to the C Scientific Calculator\n");

    // request user input for operator and numbers
    printf("Please enter an operator (+, -, *, /, ^, r) and two numbers separated by spaces: ");
    scanf("%c %lf %lf", &operator, &num1, &num2);

    // perform calculation based on operator
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
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
            break;
        case '^':
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf", num1, num2, result);
            break;
        case 'r':
            result = pow(num2, 1.0/num1);
            printf("root of %.2lf with index %.2lf = %.2lf", num2, num1, result);
            break;
        default:
            printf("Invalid operator!");
    }

    printf("\nThank you for using the C Scientific Calculator");
    return 0;
}