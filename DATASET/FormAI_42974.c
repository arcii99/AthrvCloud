//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double num1, num2, result;

    printf("Welcome to the Scientific Calculator\n");

    while (1) {
        printf("Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Sine\n");
        printf("6. Cosine\n");
        printf("7. Tangent\n");
        printf("8. Logarithm\n");
        printf("9. Exponential\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("Result: %lf\n", result);
                break;
            case 2:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("Result: %lf\n", result);
                break;
            case 3:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("Result: %lf\n", result);
                break;
            case 4:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                if (num2 == 0) {
                    printf("Error: division by zero\n");
                    break;
                }
                result = num1 / num2;
                printf("Result: %lf\n", result);
                break;
            case 5:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * M_PI / 180);
                printf("Result: %lf\n", result);
                break;
            case 6:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = cos(num1 * M_PI / 180);
                printf("Result: %lf\n", result);
                break;
            case 7:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                result = tan(num1 * M_PI / 180);
                printf("Result: %lf\n", result);
                break;
            case 8:
                printf("Enter number: ");
                scanf("%lf", &num1);
                if (num1 <= 0) {
                    printf("Error: negative or zero argument\n");
                    break;
                }
                result = log(num1);
                printf("Result: %lf\n", result);
                break;
            case 9:
                printf("Enter number: ");
                scanf("%lf", &num1);
                result = exp(num1);
                printf("Result: %lf\n", result);
                break;
            case 10:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}