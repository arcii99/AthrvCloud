//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include<stdio.h>
#include<math.h>

int main()
{
    char operator;
    float num1, num2, result;

    printf("Enter an operator (+, -, *, /, ^, %%): ");
    scanf("%c", &operator);

    printf("Enter first operand: ");
    scanf("%f", &num1);

    printf("Enter second operand: ");
    scanf("%f", &num2);

    switch(operator)
    {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f", result);
            break;

        case '-':
            result = num1 - num2;
            printf("Result: %.2f", result);
            break;

        case '*':
            result = num1 * num2;
            printf("Result: %.2f", result);
            break;

        case '/':
            if(num2 != 0)
            {
                result = num1 / num2;
                printf("Result: %.2f", result);
            }
            else
            {
                printf("Error: Division by zero");
            }
            break;

        case '^':
            result = pow(num1, num2);
            printf("Result: %.2f", result);
            break;

        case '%':
            result = fmod(num1, num2);
            printf("Result: %.2f", result);
            break;

        default:
            printf("Error: Invalid operator entered");
            break;
    }

    return 0;
}