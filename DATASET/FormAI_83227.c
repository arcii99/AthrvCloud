//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: introspective
#include<stdio.h>
#include<math.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Welcome to my scientific calculator!\n");
    printf("Enter the operation you would like to perform (+, -, *, /, ^, sqrt): ");
    scanf("%c", &operator);

    switch(operator) {
        case '+':
            printf("Enter two numbers to add: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
            break;

        case '-':
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
            break;

        case '*':
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
            break;

        case '/':
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
            break;

        case '^':
            printf("Enter a base number and an exponent: ");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf", num1, num2, result);
            break;

        case 'sqrt':
            printf("Enter a number to find the square root: ");
            scanf("%lf", &num1);
            result = sqrt(num1);
            printf("sqrt(%.2lf) = %.2lf", num1, result);
            break;

        default:
            printf("Invalid operator entered!");
    }

    return 0;
}