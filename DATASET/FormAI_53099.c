//FormAI DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char operator;
    double first, second;

    printf("Please enter a simple arithmetic expression in the following format: [number] [operator] [number]\n");
    scanf("%lf %c %lf", &first, &operator, &second);

    switch (operator)
    {
        case '+':
            printf("%.2lf + %.2lf = %.2lf", first, second, first + second);
            break;

        case '-':
            printf("%.2lf - %.2lf = %.2lf", first, second, first - second);
            break;

        case '*':
            printf("%.2lf * %.2lf = %.2lf", first, second, first * second);
            break;

        case '/':
            printf("%.2lf / %.2lf = %.2lf", first, second, first / second);
            break;

        default:
            printf("Invalid operator");
            break;
    }

    return 0;
}