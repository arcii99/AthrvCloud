//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: standalone
#include <stdio.h>
#include <math.h>

int main()
{
    char operator;      // variable for the operator entered by the user
    double num1, num2;  // variables for the two numbers entered by the user

    printf("Enter an operator (+, -, *, /, ^, %%): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch(operator)
    {
        case '+':
            printf("%.2lf + %.2lf = %.2lf", num1, num2, num1 + num2);
            break;

        case '-':
            printf("%.2lf - %.2lf = %.2lf", num1, num2, num1 - num2);
            break;

        case '*':
            printf("%.2lf * %.2lf = %.2lf", num1, num2, num1 * num2);
            break;

        case '/':
            // Check if the second number is zero
            if(num2 == 0)
                printf("Error: Division by zero");
            else
                printf("%.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
            break;

        case '^':
            printf("%.2lf ^ %.2lf = %.2lf", num1, num2, pow(num1, num2));
            break;

        case '%':
            // Check if the second number is zero
            if(num2 == 0)
                printf("Error: Division by zero");
            else
                printf("%.2lf %% %.2lf = %.2lf", num1, num2, fmod(num1, num2));
            break;

        default:
            printf("Error: Invalid operator");
    }

    return 0;
}