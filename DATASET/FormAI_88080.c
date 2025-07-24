//FormAI DATASET v1.0 Category: Scientific ; Style: bold
#include <stdio.h>

int main() {

    printf("Performing scientific calculations using C programming.\n");

    double num1, num2;
    char operator;

    printf("Enter a mathematical operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter a number: ");
    scanf("%lf", &num1);

    printf("Enter another number: ");
    scanf("%lf", &num2);

    switch(operator) {
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
            if(num2 == 0) {
                printf("Error: Division by zero");
            } else {
                printf("%.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
            }
            break;

        default:
            printf("Error: Invalid operator");
            break;
    }

    return 0;
}