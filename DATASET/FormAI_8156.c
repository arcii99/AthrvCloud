//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char op;

    printf("Enter a number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /, ^, %%): ");
    scanf(" %c", &op);

    if (op == '+') {
        printf("Enter another number: ");
        scanf("%lf", &num2);
        result = num1 + num2;
        printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
    } 
    else if (op == '-') {
        printf("Enter another number: ");
        scanf("%lf", &num2);
        result = num1 - num2;
        printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
    } 
    else if (op == '*') {
        printf("Enter another number: ");
        scanf("%lf", &num2);
        result = num1 * num2;
        printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
    } 
    else if (op == '/') {
        printf("Enter another number: ");
        scanf("%lf", &num2);
        if (num2 == 0) {
            printf("Error: Division by zero");
            exit(0);
        }
        result = num1 / num2;
        printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
    } 
    else if (op == '^') {
        printf("Enter power: ");
        scanf("%lf", &num2);
        result = pow(num1, num2);
        printf("%.2lf ^ %.2lf = %.2lf", num1, num2, result);
    } 
    else if (op == '%') {
        printf("Enter another number: ");
        scanf("%lf", &num2);
        result = fmod(num1, num2);
        printf("%.2lf %% %.2lf = %.2lf", num1, num2, result);
    } 
    else {
        printf("Invalid operator");
        exit(0);
    }

    return 0;
}