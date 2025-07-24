//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <math.h>

int main()
{
    double num1, num2, result;
    char op;

    printf("Enter operator (+, -, *, /, ^): ");
    scanf("%c", &op);

    switch(op)
    {
        case '+':
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
            break;

        case '-':
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
            break;

        case '*':
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
            break;

        case '/':
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);

            while(num2 == 0)
            {
                printf("Error! Cannot divide by zero.\n");
                printf("Enter a non-zero second number: ");
                scanf("%lf", &num2);
            }

            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
            break;

        case '^':
            printf("Enter the number to be raised: ");
            scanf("%lf", &num1);
            printf("Enter the power: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf", num1, num2, result);
            break;

        default:
            printf("Error! Invalid operator.");
    }
    return 0;
}