//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    float num1, num2, result;

    // Display menu
    printf("Scientific Calculator Operations\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power of a Number\n");
    printf("6. Square Root of a Number\n");
    printf("7. Sin Function\n");
    printf("8. Cos Function\n");
    printf("9. Tan Function\n");
    printf("10. Logarithm Function\n");
    printf("11. Exit\n");

    // Read user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the selected operation
    switch(choice) {
        case 1: // Addition
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("Result = %.2f", result);
            break;

        case 2: // Subtraction
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("Result = %.2f", result);
            break;

        case 3: // Multiplication
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("Result = %.2f", result);
            break;

        case 4: // Division
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 / num2;
            printf("Result = %.2f", result);
            break;

        case 5: // Power of a Number
            printf("Enter the base number: ");
            scanf("%f", &num1);
            printf("Enter the exponent: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("Result = %.2f", result);
            break;

        case 6: // Square Root of a Number
            printf("Enter a number: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("Result = %.2f", result);
            break;

        case 7: // Sin Function
            printf("Enter an angle in degrees: ");
            scanf("%f", &num1);
            result = sin(num1 * M_PI / 180.0);
            printf("Result = %.2f", result);
            break;

        case 8: // Cos Function
            printf("Enter an angle in degrees: ");
            scanf("%f", &num1);
            result = cos(num1 * M_PI / 180.0);
            printf("Result = %.2f", result);
            break;

        case 9: // Tan Function
            printf("Enter an angle in degrees: ");
            scanf("%f", &num1);
            result = tan(num1 * M_PI / 180.0);
            printf("Result = %.2f", result);
            break;

        case 10: // Logarithm Function
            printf("Enter a number: ");
            scanf("%f", &num1);
            result = log10(num1);
            printf("Result = %.2f", result);
            break;

        case 11: // Exit
            printf("Thank you for using the calculator!");
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}