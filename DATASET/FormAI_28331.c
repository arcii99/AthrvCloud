//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to add two numbers
double add(double num1, double num2) {
    return num1 + num2;
}

// Function to subtract two numbers
double subtract(double num1, double num2) {
    return num1 - num2;
}

// Function to multiply two numbers
double multiply(double num1, double num2) {
    return num1 * num2;
}

// Function to divide two numbers
double divide(double num1, double num2) {
    return num1 / num2;
}

// Function to calculate power of a number
double power(double base, double exponent) {
    return pow(base, exponent);
}

// Function to calculate square root of a number
double squareRoot(double num) {
    return sqrt(num);
}

// Function to calculate factorial of a number
double factorial(double num) {
    int i;
    double result = 1;

    if (num < 0) {
        return -1;
    }

    for (i = 1; i <= num; i++) {
        result *= i;
    }

    return result;
}

// Function to calculate sin value of an angle
double sine(double angle) {
    return sin(angle);
}

// Function to calculate cos value of an angle
double cosine(double angle) {
    return cos(angle);
}

// Function to calculate tan value of an angle
double tangent(double angle) {
    return tan(angle);
}

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        // Display menu
        printf("\n----- Scientific Calculator Menu -----\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Power\n");
        printf("6. Square root\n");
        printf("7. Factorial\n");
        printf("8. Sin\n");
        printf("9. Cos\n");
        printf("10. Tan\n");
        printf("11. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 11) {
            break;
        }

        if (choice == 6 || choice == 7 || choice == 8 || choice == 9 || choice == 10) {
            printf("Enter a number: ");
            scanf("%lf", &num1);
        }

        else {
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
        }

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                result = subtract(num1, num2);
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                result = multiply(num1, num2);
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                if (num2 == 0) {
                    printf("Cannot divide by zero\n");
                    break;
                }
                result = divide(num1, num2);
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 5:
                result = power(num1, num2);
                printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 6:
                result = squareRoot(num1);
                printf("Square root of %.2lf = %.2lf\n", num1, result);
                break;

            case 7:
                result = factorial(num1);
                if (result == -1) {
                    printf("Factorial of negative number does not exist\n");
                    break;
                }
                printf("Factorial of %.2lf = %.2lf\n", num1, result);
                break;

            case 8:
                result = sine(num1);
                printf("Sin of %.2lf = %.2lf\n", num1, result);
                break;

            case 9:
                result = cosine(num1);
                printf("Cos of %.2lf = %.2lf\n", num1, result);
                break;

            case 10:
                result = tangent(num1);
                printf("Tan of %.2lf = %.2lf\n", num1, result);
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}