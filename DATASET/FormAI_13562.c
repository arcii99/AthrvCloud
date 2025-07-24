//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: medieval
#include <stdio.h>
#include <math.h>

int main()
{
    char operator;
    double num1, num2, result;

    printf("Enter operator (+, -, *, /, ^, sqrt): ");
    scanf("%c", &operator);

    if (operator == 'sqrt')
    {
        printf("Enter a number: ");
        scanf("%lf", &num1);
        result = sqrt(num1);
        printf("Square root of %.2lf is %.2lf", num1, result);
    }
    else
    {
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);

        switch(operator)
        {
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

            default:
                printf("Invalid operator");
                break;
        }
    }
    return 0;
}