//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    char operator;
    float x, y, result;

    printf("Enter an operator (+, -, *, /, ^, %%): ");
    scanf("%c", &operator);
    printf("Enter two operands: ");
    scanf("%f %f", &x, &y);

    switch (operator) {
        case '+':
            result = x + y;
            printf("%.2f + %.2f = %.2f", x, y, result);
            break;

        case '-':
            result = x - y;
            printf("%.2f - %.2f = %.2f", x, y, result);
            break;

        case '*':
            result = x * y;
            printf("%.2f * %.2f = %.2f", x, y, result);
            break;

        case '/':
            if (y != 0) {
                result = x / y;
                printf("%.2f / %.2f = %.2f", x, y, result);
            } else {
                printf("Cannot divide by zero");
            }
            break;

        case '^':
            result = pow(x, y);
            printf("%.2f ^ %.2f = %.2f", x, y, result);
            break;

        case '%':
            result = fmod(x, y);
            printf("%.2f %% %.2f = %.2f", x, y, result);
            break;

        default:
            printf("Invalid operator");
    }

    return 0;
}