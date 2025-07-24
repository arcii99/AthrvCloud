//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char operator;

    printf("Welcome to the C Scientific Calculator!\n");
    printf("Please enter your first number: ");
    scanf("%lf", &num1);

    printf("Select an operator (+, -, *, /, ^, r): ");
    scanf(" %c", &operator);

    if (operator == 'r') {
        result = sqrt(num1);
        printf("The square root of %.2lf is %.2lf\n", num1, result);
    }
    else {
        printf("Please enter your second number: ");
        scanf("%lf", &num2);

        switch (operator) {
            case '+':
                result = num1 + num2;
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '-':
                result = num1 - num2;
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '*':
                result = num1 * num2;
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '/':
                result = num1 / num2;
                if (num2 == 0) {
                    printf("Error: Cannot divide by zero\n");
                } else {
                    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
            case '^':
                result = pow(num1, num2);
                printf("%.2lf to the power of %.2lf is %.2lf\n", num1, num2, result);
                break;
            default:
                printf("Error: Invalid operator\n");
                break;
        }
    }

    printf("Thank you for using the C Scientific Calculator!\n");
    return 0;
}