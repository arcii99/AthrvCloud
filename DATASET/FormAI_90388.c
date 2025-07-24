//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cryptic
#include <stdio.h>
#include <math.h>

int main()
{
    char operator;
    double num1, num2, result;

    printf("Enter an operator (+, -, *, /, ^, %%): ");
    scanf("%c", &operator);

    switch(operator)
    {
        case '+': // Addition
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("Result: %.2lf", result);
            break;
        case '-': // Subtraction
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("Result: %.2lf", result);
            break;
        case '*': // Multiplication
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("Result: %.2lf", result);
            break;
        case '/': // Division
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            if(num2 == 0)
                printf("Error: Cannot divide by zero");
            else{
                result = num1 / num2;
                printf("Result: %.2lf", result);
            }
            break;
        case '^': // Exponentiation
            printf("Enter base number: ");
            scanf("%lf", &num1);
            printf("Enter exponent number: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("Result: %.2lf", result);
            break;
        case '%': // Modulus
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            if(num2 == 0)
                printf("Error: Cannot divide by zero");
            else{
                result = fmod(num1,num2);
                printf("Result: %.2lf", result);
            }
            break;
        default:
            printf("Error: Invalid operator");
    }
    return 0;
}