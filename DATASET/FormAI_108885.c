//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double num1, num2, result;
    char operator;

    printf("Welcome to the Amazing Scientific Calculator!\n");
    printf("Please enter the first number: ");
    scanf("%lf", &num1);

    printf("\nPlease enter the desired operator (+, -, *, /, ^, s): ");
    scanf(" %c", &operator);

    if(operator == 's')
    {
        result = sin(num1);
        printf("\nThe sine of %.2lf is: %.2lf", num1, result);
    }
    else
    {
        printf("\nPlease enter the second number: ");
        scanf("%lf", &num2);

        switch(operator)
        {
            case '+':
                result = num1 + num2;
                printf("\nThe sum of %.2lf and %.2lf is: %.2lf", num1, num2, result);
                break;

            case '-':
                result = num1 - num2;
                printf("\nThe difference between %.2lf and %.2lf is: %.2lf", num1, num2, result);
                break;

            case '*':
                result = num1 * num2;
                printf("\nThe product of %.2lf and %.2lf is: %.2lf", num1, num2, result);
                break;

            case '/':
                if(num2 == 0)
                {
                    printf("\nError: Division by zero!");
                }
                else
                {
                    result = num1 / num2;
                    printf("\nThe quotient of %.2lf and %.2lf is: %.2lf", num1, num2, result);
                }
                break;

            case '^':
                result = pow(num1, num2);
                printf("\n%.2lf raised to the power of %.2lf is: %.2lf", num1, num2, result);
                break;

            default:
                printf("\nInvalid operator selected!");
        }
    }

    printf("\n\nThank you for using the Amazing Scientific Calculator!");
    return 0;
}