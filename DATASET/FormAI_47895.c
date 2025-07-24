//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include <stdio.h>
#include <math.h>

int main() {
    int option;
    double num1, num2, result;

    printf("Welcome to the C Scientific Calculator\n");

    printf("Please choose an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power of a number\n");
    printf("6. Square root\n");
    printf("7. Logarithm with base 10\n");
    printf("8. Sine function\n");
    printf("9. Cosine function\n");
    printf("10. Tangent function\n");

    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            if(num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
            }
            break;
        case 5:
            printf("Enter the base number: ");
            scanf("%lf", &num1);
            printf("Enter the exponent: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 6:
            printf("Enter the number: ");
            scanf("%lf", &num1);
            if(num1 < 0) {
                printf("Error: Cannot take square root of a negative number\n");
            } else {
                result = sqrt(num1);
                printf("Result: %.2lf\n", result);
            }
            break;
        case 7:
            printf("Enter the number: ");
            scanf("%lf", &num1);
            if(num1 <= 0) {
                printf("Error: Cannot take logarithm of a non-positive number\n");
            } else {
                result = log10(num1);
                printf("Result: %.2lf\n", result);
            }
            break;
        case 8:
            printf("Enter the angle in degrees: ");
            scanf("%lf", &num1);
            result = sin(num1 * M_PI / 180);
            printf("Result: %.2lf\n", result);
            break;
        case 9:
            printf("Enter the angle in degrees: ");
            scanf("%lf", &num1);
            result = cos(num1 * M_PI / 180);
            printf("Result: %.2lf\n", result);
            break;
        case 10:
            printf("Enter the angle in degrees: ");
            scanf("%lf", &num1);
            result = tan(num1 * M_PI / 180);
            printf("Result: %.2lf\n", result);
            break;
        default:
            printf("Error: Invalid option\n");
    }

    return 0;
}