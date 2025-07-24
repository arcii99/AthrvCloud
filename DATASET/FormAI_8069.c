//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complex
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Welcome to the Scientific Calculator!\n\n");

    char operation;
    printf("Please select an operation (+, -, *, /, ^, s, c): ");
    scanf("%c", &operation);

    double num1, num2, result;
    switch(operation)
    {
        case '+':
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '-':
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '*':
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '/':
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            if(num2 == 0)
            {
                printf("Error: cannot divide by zero\n");
            }
            else
            {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;

        case '^':
            printf("Enter base number: ");
            scanf("%lf", &num1);
            printf("Enter exponent number: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 's':
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = sin(num1);
            printf("sin(%.2lf) = %.2lf\n", num1, result);
            break;

        case 'c':
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = cos(num1);
            printf("cos(%.2lf) = %.2lf\n", num1, result);
            break;

        default:
            printf("Error: invalid operation entered\n");
            break;
    }

    return 0;
}