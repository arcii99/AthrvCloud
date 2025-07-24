//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: optimized
#include <stdio.h>
#include <math.h>

/* Function to perform addition */
double calculate_addition(double num1, double num2) {
    return num1 + num2;
}

/* Function to perform subtraction */
double calculate_subtraction(double num1, double num2) {
    return num1 - num2;
}

/* Function to perform multiplication */
double calculate_multiplication(double num1, double num2) {
    return num1 * num2;
}

/* Function to perform division */
double calculate_division(double num1, double num2) {
    if (num2 != 0) {
        return num1 / num2;
    }
    else {
        printf("Error: Division by zero!\n");
        return NAN; // Return NaN (Not-a-Number) value for error handling
    }
}

/* Function to calculate power */
double calculate_power(double base, double exponent) {
    return pow(base, exponent);
}

/* Function to calculate square root */
double calculate_sqrt(double num) {
    if (num >= 0) {
        return sqrt(num);
    }
    else {
        printf("Error: Square root of negative number!\n");
        return NAN; // Return NaN (Not-a-Number) value for error handling
    }
}

/* Function to calculate factorial */
double calculate_factorial(int num) {
    double result = 1;
    if (num < 0) {
        printf("Error: Factorial of negative number!\n");
        return NAN; // Return NaN (Not-a-Number) value for error handling
    }
    else {
        for (int i = 1; i <= num; i++) {
            result *= i;
        }
        return result;
    }
}

int main() {
    int choice;
    double num1, num2, result;

    printf("Welcome to the Scientific Calculator\n");
    printf("-----------------------------------\n");

    do {
        printf("\nPlease select an operation from the list below:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Square Root\n");
        printf("7. Factorial\n");
        printf("8. Exit\n");

        printf("\nEnter your choice (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Addition
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                result = calculate_addition(num1, num2);
                printf("Result: %lf\n", result);
                break;

            case 2: // Subtraction
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                result = calculate_subtraction(num1, num2);
                printf("Result: %lf\n", result);
                break;

            case 3: // Multiplication
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                result = calculate_multiplication(num1, num2);
                printf("Result: %lf\n", result);
                break;

            case 4: // Division
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                result = calculate_division(num1, num2);
                if (!isnan(result)) {
                    printf("Result: %lf\n", result);
                }
                break;

            case 5: // Power
                printf("Enter the base: ");
                scanf("%lf", &num1);
                printf("Enter the exponent: ");
                scanf("%lf", &num2);
                result = calculate_power(num1, num2);
                printf("Result: %lf\n", result);
                break;

            case 6: // Square root
                printf("Enter the number: ");
                scanf("%lf", &num1);
                result = calculate_sqrt(num1);
                if (!isnan(result)) {
                    printf("Result: %lf\n", result);
                }
                break;

            case 7: // Factorial
                printf("Enter the number: ");
                scanf("%lf", &num1);
                result = calculate_factorial((int)num1);
                if (!isnan(result)) {
                    printf("Result: %lf\n", result);
                }
                break;

            case 8: // Exit
                printf("Thank you for using the Scientific Calculator.\n");
                break;

            default: // Invalid choice
                printf("Invalid choice. Please enter a valid choice (1-8).\n");
                break;
        }
    } while (choice != 8);

    return 0;
}