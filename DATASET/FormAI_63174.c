//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

int main() {
    printf("C Scientific Calculator\n");
    printf("=======================\n");

    double num1, num2, result;
    char operator;

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter operator (+, -, *, /, ^, sqrt): ");
    scanf(" %c", &operator);

    if (operator == 'sqrt') {
        result = sqrt(num1);
        printf("Result: %lf\n", result);
    } else {
        printf("Enter second number: ");
        scanf("%lf", &num2);

        switch (operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            case '^':
                result = pow(num1, num2);
                break;
            default:
                printf("Invalid operator\n");
                return 1;
        }

        printf("Result: %lf\n", result);
    }
    
    return 0;
}