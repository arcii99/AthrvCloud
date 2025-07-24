//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main() {
    float num1, num2, result;
    char operator;

    printf("Welcome to the scientific calculator!\n\n");

    printf("Please enter the first number: ");
    scanf("%f", &num1);

    printf("Please select an operator (+, -, *, /, ^, s): ");
    scanf(" %c", &operator);

    switch(operator) {
        case '+':
            printf("Please enter the second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("The result is: %f\n", result);
            break;
        case '-':
            printf("Please enter the second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("The result is: %f\n", result);
            break;
        case '*':
            printf("Please enter the second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("The result is: %f\n", result);
            break;
        case '/':
            printf("Please enter the second number: ");
            scanf("%f", &num2);
            result = num1 / num2;
            printf("The result is: %f\n", result);
            break;
        case '^':
            printf("Please enter the power: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("The result is: %f\n", result);
            break;
        case 's':
            result = sqrt(num1);
            printf("The square root of %f is: %f\n", num1, result);
            break;
        default:
            printf("Error: Invalid operator selected.\n");
            break;
    }

    return 0;
}