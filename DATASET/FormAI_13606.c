//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>

int main()
{
    double num1, num2, result;
    char operator;

    printf("Welcome to the Cyberpunk Scientific Calculator\n");
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the operator (+, -, *, /, ^, s, c, t): ");
    scanf(" %c", &operator);

    switch(operator)
    {
        case '+':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("Result: %lf\n", result);
            break;
        case '-':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("Result: %lf\n", result);
            break;
        case '*':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("Result: %lf\n", result);
            break;
        case '/':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 / num2;
            printf("Result: %lf\n", result);
            break;
        case '^':
            printf("Enter the power: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("Result: %lf\n", result);
            break;
        case 's':
            result = sin(num1);
            printf("Result: %lf\n", result);
            break;
        case 'c':
            result = cos(num1);
            printf("Result: %lf\n", result);
            break;
        case 't':
            result = tan(num1);
            printf("Result: %lf\n", result);
            break;
        default:
            printf("Invalid operator\n");
    }

    return 0;
}