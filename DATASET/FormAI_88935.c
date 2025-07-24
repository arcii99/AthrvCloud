//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <math.h>

int main() {
    // defining variables for calculator operations
    char operation;
    float num1, num2, result;

    printf("Welcome to our scientific calculator!\n\n");

    // adding a menu of calculator operations
    printf("Enter the operation you want to perform:\n");
    printf("\t1. Addition (+)\n");
    printf("\t2. Subtraction (-)\n");
    printf("\t3. Multiplication (*)\n");
    printf("\t4. Division (/)\n");
    printf("\t5. Square Root (sqrt)\n");
    printf("\t6. Natural Logarithm (ln)\n");
    printf("\t7. Power (^)\n\n");

    scanf("%c", &operation);

    // implementing each calculator operation using switch case statement
    switch (operation) {
        case '+':
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f", num1, num2, result);
            break;

        case '-':
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f", num1, num2, result);
            break;

        case '*':
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f", num1, num2, result);
            break;

        case '/':
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 / num2;
            printf("%.2f / %.2f = %.2f", num1, num2, result);
            break;

        case 'sqrt':
            printf("Enter number: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("sqrt(%.2f) = %.2f", num1, result);
            break;

        case 'ln':
            printf("Enter number: ");
            scanf("%f", &num1);
            result = log(num1);
            printf("ln(%.2f) = %.2f", num1, result);
            break;

        case '^':
            printf("Enter base: ");
            scanf("%f", &num1);
            printf("Enter exponent: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("%.2f ^ %.2f = %.2f", num1, num2, result);
            break;

        default:
            printf("Invalid operation... Please choose a valid option.");
    }

    printf("\n\nThank you for using our scientific calculator!\n");

    return 0;
}