//FormAI DATASET v1.0 Category: Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a, b, result;
    char operator;

    printf("Enter an expression: ");
    scanf("%lf %c %lf", &a, &operator, &b);

    switch (operator)
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        case '^':
            result = pow(a, b);
            break;
        case '%':
            result = fmod(a, b);
            break;
        default:
            printf("Invalid operator");
            exit(0);
    }

    printf("Result: %lf", result);

    return 0;
}