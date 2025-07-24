//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);

int main() {
    double num1, num2, result;
    int choice;
    char restart;

    do {
        // ask user for input
        printf("\nEnter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        // display menu options
        printf("\n");
        printf("1. Add (+)\n");
        printf("2. Subtract (-)\n");
        printf("3. Multiply (*)\n");
        printf("4. Divide (/)\n");
        printf("5. Power (^)\n");
        printf("\nEnter your choice: ");

        // get user's choice
        scanf("%d", &choice);

        // perform operation based on user's choice
        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("\n%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("\n%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("\n%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                result = divide(num1, num2);
                printf("\n%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 5:
                result = power(num1, num2);
                printf("\n%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

        // ask user if they want to perform another calculation
        printf("\nDo you want to perform another calculation? (y/n): ");
        scanf(" %c", &restart);

    } while (restart == 'y' || restart == 'Y');

    printf("\nThank you for using this calculator. Goodbye!\n");

    return 0;
}

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 == 0) {
        printf("\nError: Cannot divide by zero!\n");
        exit(1);
    }
    return num1 / num2;
}

double power(double num1, double num2) {
    return pow(num1, num2);
}