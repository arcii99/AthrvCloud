//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include <stdio.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Welcome to the C Scientific Calculator!\n");
    printf("Enter an operator (+, -, *, /, ^, s, c, t, l): ");
    scanf("%c", &operator);

    switch (operator) {
        case '+':
            printf("Enter two numbers to add: \n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '-':
            printf("Enter two numbers to subtract: \n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '*':
            printf("Enter two numbers to multiply: \n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '/':
            printf("Enter two numbers to divide: \n");
            scanf("%lf %lf", &num1, &num2);
            if (num2 == 0) {
                printf("Error: Cannot divide by zero.");
            } else {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;

        case '^':
            printf("Enter two numbers to calculate power: \n");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 's':
            printf("Enter a number to calculate the sine: \n");
            scanf("%lf", &num1);
            result = sin(num1);
            printf("sin(%.2lf) = %.2lf\n", num1, result);
            break;

        case 'c':
            printf("Enter a number to calculate the cosine: \n");
            scanf("%lf", &num1);
            result = cos(num1);
            printf("cos(%.2lf) = %.2lf\n", num1, result);
            break;

        case 't':
            printf("Enter a number to calculate the tangent: \n");
            scanf("%lf", &num1);
            result = tan(num1);
            printf("tan(%.2lf) = %.2lf\n", num1, result);
            break;

        case 'l':
            printf("Enter a number to calculate the natural logarithm: \n");
            scanf("%lf", &num1);
            result = log(num1);
            printf("ln(%.2lf) = %.2lf\n", num1, result);
            break;

        default:
            printf("Error: Invalid operator entered. Please enter a valid operator.");
            break;
    }

    return 0;
}