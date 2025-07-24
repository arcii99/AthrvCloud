//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: imaginative
#include <stdio.h>
#include <math.h>

//Function to add two numbers
double add(double a, double b) {
    return a + b;
}

//Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

//Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

//Function to divide two numbers
double divide(double a, double b) {
    return a / b;
}

//Function to take square root of a number
double squareRoot(double a) {
    return sqrt(a);
}

//Function to take power of a number
double power(double a, double b) {
    return pow(a, b);
}

int main() {
    double num1, num2, result;
    int choice;

    printf("Welcome to C Scientific Calculator\n");

    while (1) {
        // prompt user to enter first number
        printf("Enter first number: ");
        scanf("%lf", &num1);

        // prompt user to enter second number
        printf("Enter second number: ");
        scanf("%lf", &num2);

        printf("\nSelect the operation to perform:\n");
        printf("------------------------------------\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square Root\n");
        printf("6. Power\n");
        printf("7. Exit\n");
        printf("------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("The sum of %.2lf and %.2lf is %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("The difference between %.2lf and %.2lf is %.2lf\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("The product of %.2lf and %.2lf is %.2lf\n", num1, num2, result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Division by zero is not allowed!\n");
                } else {
                    result = divide(num1, num2);
                    printf("%.2lf divided by %.2lf is %.2lf\n", num1, num2, result);
                }
                break;
            case 5:
                if (num1 < 0) {
                    printf("Square root of a negative number is not allowed!\n");
                } else {
                    result = squareRoot(num1);
                    printf("The square root of %.2lf is %.2lf\n", num1, result);
                }
                break;
            case 6:
                result = power(num1, num2);
                printf("%.2lf raised to the power of %.2lf is %.2lf\n", num1, num2, result);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid input! Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}