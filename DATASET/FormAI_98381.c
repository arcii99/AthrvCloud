//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    return a / b;
}

// Function to perform modulus
double modulus(double a, double b) {
    return fmod(a,b);
}

// Function to perform power
double power(double a, double b) {
    return pow(a,b);
}

int main() {
    double num1, num2, result;
    int choice;

    printf("\nWelcome to the Happy Scientific Calculator!");

    do {
        printf("\nWhat operation would you like to perform?");
        printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n6. Power\n7. Exit");
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = add(num1, num2);
                printf("\nThe sum of %.2lf and %.2lf is: %.2lf", num1, num2, result);
                break;

            case 2:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = subtract(num1, num2);
                printf("\nThe difference between %.2lf and %.2lf is: %.2lf", num1, num2, result);
                break;

            case 3:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = multiply(num1, num2);
                printf("\nThe product of %.2lf and %.2lf is: %.2lf", num1, num2, result);
                break;

            case 4:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                if (num2 == 0) {
                    printf("\nError: Division by zero is not possible!");
                    break;
                }
                result = divide(num1, num2);
                printf("\nThe quotient of %.2lf and %.2lf is: %.2lf", num1, num2, result);
                break;

            case 5:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                if (num2 == 0) {
                    printf("\nError: Modulus by zero is not possible!");
                    break;
                }
                result = modulus(num1, num2);
                printf("\nThe modulus of %.2lf and %.2lf is: %.2lf", num1, num2, result);
                break;

            case 6:
                printf("\nEnter base: ");
                scanf("%lf", &num1);
                printf("Enter exponent: ");
                scanf("%lf", &num2);
                result = power(num1, num2);
                printf("\n%.2lf raised to the power of %.2lf is: %.2lf", num1, num2, result);
                break;

            case 7:
                printf("\nThank you for using the Happy Scientific Calculator! Have a great day :)");
                exit(0);

            default:
                printf("\nInvalid choice, please try again.");
        }
    } while (choice != 7);

    return 0;
}