//FormAI DATASET v1.0 Category: Arithmetic ; Style: intelligent
/* A Program to Perform Arithmetic Operations */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double num1, num2;
    char operator;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    printf("Enter an arithmetic operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch(operator)
    {
        case '+':
            printf("%.2lf + %.2lf = %.2lf", num1, num2, num1+num2);
            break;

        case '-':
            printf("%.2lf - %.2lf = %.2lf", num1, num2, num1-num2);
            break;

        case '*':
            printf("%.2lf * %.2lf = %.2lf", num1, num2, num1*num2);
            break;

        case '/':
            if(num2 == 0)
            {
                printf("Error: Cannot divide by zero");
            }
            else
            {
                printf("%.2lf / %.2lf = %.2lf", num1, num2, num1/num2);
            }
            break;

        default:
            printf("Invalid operator entered");
    }

    return 0;
}