//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: active
#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char operator;

    printf("Welcome to the Scientific Calculator Program!\n");
    printf("Please enter your equation in the following format: [number][operator][number]\n");
    printf("Supported operators: +, -, *, /, ^ (for power), s (for sin), c (for cos), t (for tan)\n");

    scanf("%lf %c %lf", &num1, &operator, &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("The result is: %.2lf\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("The result is: %.2lf\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("The result is: %.2lf\n", result);
            break;
        case '/':
            result = num1 / num2;
            printf("The result is: %.2lf\n", result);
            break;
        case '^':
            result = pow(num1, num2);
            printf("The result is: %.2lf\n", result);
            break;
        case 's':
            result = sin(num1);
            printf("The result is: %.2lf\n", result);
            break;
        case 'c':
            result = cos(num1);
            printf("The result is: %.2lf\n", result);
            break;
        case 't':
            result = tan(num1);
            printf("The result is: %.2lf\n", result);
            break;
        default:
            printf("Invalid operator!\n");
            break;
    }

    return 0;
}