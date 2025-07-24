//FormAI DATASET v1.0 Category: Arithmetic ; Style: future-proof
#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    switch(operator)
    {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            if(num2 == 0)
            {
                printf("Error: division by zero");
                return 1;
            }
            else
            {
                result = num1 / num2;
                break;
            }

        default:
            printf("Error: invalid operator");
            return 1;
    }

    printf("%.2f %c %.2f = %.2f", num1, operator, num2, result);
    return 0;
}