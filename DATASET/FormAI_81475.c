//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: lively
#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char op;

    printf("Welcome to C Scientific Calculator!\n");
    printf("Please enter an operation (+, -, *, /, ^, s, c, t, l): ");
    scanf("%c", &op);

    switch(op) {
        case '+':
            printf("Please enter the first number: ");
            scanf("%lf", &num1);
            printf("Please enter the second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
            break;
        case '-':
            printf("Please enter the first number: ");
            scanf("%lf", &num1);
            printf("Please enter the second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
            break;
        case '*':
            printf("Please enter the first number: ");
            scanf("%lf", &num1);
            printf("Please enter the second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
            break;
        case '/':
            printf("Please enter the numerator: ");
            scanf("%lf", &num1);
            printf("Please enter the denominator: ");
            scanf("%lf", &num2);
            if(num2 != 0) {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
            }
            else {
                printf("ERROR: Division by zero");
            }
            break;
        case '^':
            printf("Please enter the base: ");
            scanf("%lf", &num1);
            printf("Please enter the exponent: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf", num1, num2, result);
            break;
        case 's':
            printf("Please enter the angle in degrees: ");
            scanf("%lf", &num1);
            result = sin(num1 * M_PI / 180);
            printf("sin(%.2lf) = %.2lf", num1, result);
            break;
        case 'c':
            printf("Please enter the angle in degrees: ");
            scanf("%lf", &num1);
            result = cos(num1 * M_PI / 180);
            printf("cos(%.2lf) = %.2lf", num1, result);
            break;
        case 't':
            printf("Please enter the angle in degrees: ");
            scanf("%lf", &num1);
            result = tan(num1 * M_PI / 180);
            printf("tan(%.2lf) = %.2lf", num1, result);
            break;
        case 'l':
            printf("Please enter the number: ");
            scanf("%lf", &num1);
            result = log10(num1);
            printf("log(%.2lf) = %.2lf", num1, result);
            break;
        default:
            printf("ERROR: Invalid operation");
    }

    return 0;
}