//FormAI DATASET v1.0 Category: Arithmetic ; Style: scientific
#include <stdio.h>
#include <math.h>

int main()
{
    float num1, num2, result;
    char operator;

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch(operator)
    {
        case '+':
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f", num1, num2, result);
            break;

        case '/':
            if(num2 != 0)
            {
                result = num1 / num2;
                printf("%.2f / %.2f = %.2f", num1, num2, result);
            }
            else
            {
                printf("Error: Division by zero");
            }
            break;

        default:
            printf("Error: Invalid operator");
    }

    return 0;
}