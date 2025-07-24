//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double mod(double, double);
double factorial(double);
double sine(double);
double cosine(double);
double tangent(double);
double arcsin(double);
double arccos(double);
double arctan(double);

// Main program
int main() {
    double num1, num2, result;
    int choice;

    // Displaying menu
    printf("Welcome to the Scientific Calculator!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Modulus\n");
    printf("7. Factorial\n");
    printf("8. Sine\n");
    printf("9. Cosine\n");
    printf("10. Tangent\n");
    printf("11. Arcsine\n");
    printf("12. Arccosine\n");
    printf("13. Arctangent\n");
    printf("Your Choice: ");

    // Getting choice from user
    scanf("%d", &choice);

    // Getting numbers from user
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Evaluating user's choice
    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result: %.2lf\n", result);
            break;

        case 2:
            result = subtract(num1, num2);
            printf("Result: %.2lf\n", result);
            break;

        case 3:
            result = multiply(num1, num2);
            printf("Result: %.2lf\n", result);
            break;

        case 4:
            result = divide(num1, num2);
            printf("Result: %.2lf\n", result);
            break;

        case 5:
            result = power(num1, num2);
            printf("Result: %.2lf\n", result);
            break;

        case 6:
            result = mod(num1, num2);
            printf("Result: %.2lf\n", result);
            break;

        case 7:
            result = factorial(num1);
            printf("Factorial of %.2lf: %.0lf\n", num1, result);
            break;

        case 8:
            result = sine(num1);
            printf("Sine of %.2lf: %.4lf\n", num1, result);
            break;

        case 9:
            result = cosine(num1);
            printf("Cosine of %.2lf: %.4lf\n", num1, result);
            break;

        case 10:
            result = tangent(num1);
            printf("Tangent of %.2lf: %.4lf\n", num1, result);
            break;

        case 11:
            result = arcsin(num1);
            printf("Arcsine of %.2lf: %.4lf\n", num1, result);
            break;

        case 12:
            result = arccos(num1);
            printf("Arccosine of %.2lf: %.4lf\n", num1, result);
            break;

        case 13:
            result = arctan(num1);
            printf("Arctangent of %.2lf: %.4lf\n", num1, result);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

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
    if (num2 == 0) {
        printf("Cannot divide by zero!\n");
        exit(0);
    } else {
        return num1 / num2;
    }
}

// Function to calculate power of a number
double power(double num1, double num2) {
    return pow(num1, num2);
}

// Function to calculate modulus of a number
double mod(double num1, double num2) {
    return fmod(num1, num2);
}

// Function to calculate factorial of a number
double factorial(double num) {
    if (num == 0) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

// Function to calculate sine of a number
double sine(double num) {
    return sin(num);
}

// Function to calculate cosine of a number
double cosine(double num) {
    return cos(num);
}

// Function to calculate tangent of a number
double tangent(double num) {
    return tan(num);
}

// Function to calculate arcsine of a number
double arcsin(double num) {
    return asin(num);
}

// Function to calculate arccosine of a number
double arccos(double num) {
    return acos(num);
}

// Function to calculate arctangent of a number
double arctan(double num) {
    return atan(num);
}