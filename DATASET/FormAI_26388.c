//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: invasive
#include <stdio.h>
#include <math.h>

int main() {
    char op;
    float num1, num2;

    printf("Enter operator (+, -, *, /, ^, s): ");
    scanf("%c", &op);

    switch(op) {
        case '+':
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            printf("Result: %f", num1 + num2);
            break;

        case '-':
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            printf("Result: %f", num1 - num2);
            break;

        case '*':
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            printf("Result: %f", num1 * num2);
            break;

        case '/':
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            if(num2 == 0) {
                printf("Error: Division by zero");
            } else {
                printf("Result: %f", num1 / num2);
            }
            break;

        case '^':
            printf("Enter base number: ");
            scanf("%f", &num1);
            printf("Enter power number: ");
            scanf("%f", &num2);
            printf("Result: %f", pow(num1, num2));
            break;

        case 's':
            printf("Enter number: ");
            scanf("%f", &num1);
            printf("Result: %f", sqrt(num1));
            break;

        default:
            printf("Error: Invalid operator");
            break;
    }

    return 0;
}