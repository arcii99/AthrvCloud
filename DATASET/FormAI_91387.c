//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: peaceful
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double num1, num2, result;

    printf("Welcome to the Peaceful Scientific Calculator!\n\n");

    while (1) {
        printf("Select an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Square root\n");
        printf("7. Trigonometric functions (sin, cos, tan)\n");
        printf("8. Logarithm (base 10)\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for using the Peaceful Scientific Calculator! Goodbye.\n");
            break;
        }

        printf("Enter first number: ");
        scanf("%lf", &num1);

        if (choice != 6) {
            printf("Enter second number: ");
            scanf("%lf", &num2);
        }

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                break;
            case 4:
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
                break;
            case 5:
                result = pow(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 6:
                result = sqrt(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 7:
                printf("Select a function:\n");
                printf("1. sine\n");
                printf("2. cosine\n");
                printf("3. tangent\n");

                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        result = sin(num1);
                        printf("Result: %.2lf\n", result);
                        break;
                    case 2:
                        result = cos(num1);
                        printf("Result: %.2lf\n", result);
                        break;
                    case 3:
                        result = tan(num1);
                        printf("Result: %.2lf\n", result);
                        break;
                    default:
                        printf("Invalid function choice.\n");
                }
                break;
            case 8:
                result = log10(num1);
                printf("Result: %.2lf\n", result);
                break;
            default:
                printf("Invalid operation choice.\n");
        }
    }

    return 0;
}