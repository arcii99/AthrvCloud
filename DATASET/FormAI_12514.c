//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double sine(double);

int main() {
    int choice;
    double num1, num2, result;

    printf("*** Grateful Scientific Calculator ***\n");

    while (1) {
        printf("\nSelect an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Sine\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("\nThank you for using Grateful Scientific Calculator\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            printf("\nInvalid choice. Please select a valid operation.\n");
            continue;
        }

        if (choice == 6) {
            printf("\nEnter the angle in degrees: ");
            scanf("%lf", &num1);
            result = sine(num1);
        } else {
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &num1, &num2);

            switch (choice) {
                case 1: result = add(num1, num2); break;
                case 2: result = subtract(num1, num2); break;
                case 3: result = multiply(num1, num2); break;
                case 4: result = divide(num1, num2); break;
                case 5: result = power(num1, num2); break;
            }
        }

        printf("\nResult: %lf\n", result);
    }

    return 0;
}

double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    if (y == 0) {
        printf("\nError: Cannot divide by zero.\n");
        exit(EXIT_FAILURE);
    }

    return x / y;
}

double power(double x, double y) {
    return pow(x, y);
}

double sine(double x) {
    double radians = x * M_PI / 180.0;
    return sin(radians);
}