//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shocked
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double num1, num2, result;

    printf("Welcome to the Scientific Calculator\n");
    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square root\n");
    printf("6. Power\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Logarithm\n");

    printf("Enter your choice (1-10): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("Result: %lf\n", result);
            break;
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("Result: %lf\n", result);
            break;
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("Result: %lf\n", result);
            break;
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 == 0) {
                printf("Error: division by zero\n");
            } else {
                result = num1 / num2;
                printf("Result: %lf\n", result);
            }
            break;
        case 5:
            printf("Enter a number to calculate its square root: ");
            scanf("%lf", &num1);
            if (num1 < 0) {
                printf("Error: cannot calculate square root of a negative number\n");
            } else {
                result = sqrt(num1);
                printf("Result: %lf\n", result);
            }
            break;
        case 6:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            printf("Enter its power: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("Result: %lf\n", result);
            break;
        case 7:
            printf("Enter an angle in radians to calculate its sine: ");
            scanf("%lf", &num1);
            result = sin(num1);
            printf("Result: %lf\n", result);
            break;
        case 8:
            printf("Enter an angle in radians to calculate its cosine: ");
            scanf("%lf", &num1);
            result = cos(num1);
            printf("Result: %lf\n", result);
            break;
        case 9:
            printf("Enter an angle in radians to calculate its tangent: ");
            scanf("%lf", &num1);
            result = tan(num1);
            printf("Result: %lf\n", result);
            break;
        case 10:
            printf("Enter a number to calculate its natural logarithm: ");
            scanf("%lf", &num1);
            if (num1 <= 0) {
                printf("Error: cannot calculate logarithm of a non-positive number\n");
            } else {
                result = log(num1);
                printf("Result: %lf\n", result);
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}