//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genious
#include<stdio.h>
#include<math.h>

/* Function declarations */
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double square(double);
double squareRoot(double);
double power(double, double);

/* Main function */
int main() {

    int option; // Option chosen by the user
    double num1, num2, result; // Numbers entered by the user and the result of the operation

    // Menu to display options to the user
    printf("Welcome to Genius Scientific Calculator!\n");
    printf("Select an operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square\n");
    printf("6. Square Root\n");
    printf("7. Power\n");

    // Accepting user choice
    printf("Enter option (1-7): ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter two numbers for addition:\n");
            scanf("%lf %lf", &num1, &num2);
            result = add(num1, num2);
            printf("The result of addition of %.2lf and %.2lf is: %.2lf", num1, num2, result);
            break;
        case 2:
            printf("Enter two numbers for subtraction:\n");
            scanf("%lf %lf", &num1, &num2);
            result = subtract(num1, num2);
            printf("The result of subtraction of %.2lf from %.2lf is: %.2lf", num2, num1, result);
            break;
        case 3:
            printf("Enter two numbers for multiplication:\n");
            scanf("%lf %lf", &num1, &num2);
            result = multiply(num1, num2);
            printf("The result of multiplication of %.2lf and %.2lf is: %.2lf", num1, num2, result);
            break;
        case 4:
            printf("Enter two numbers for division:\n");
            scanf("%lf %lf", &num1, &num2);
            result = divide(num1, num2);
            printf("The result of division of %.2lf by %.2lf is: %.2lf", num1, num2, result);
            break;
        case 5:
            printf("Enter a number for squaring:\n");
            scanf("%lf", &num1);
            result = square(num1);
            printf("The square of %.2lf is: %.2lf", num1, result);
            break;
        case 6:
            printf("Enter a number for finding square root:\n");
            scanf("%lf", &num1);
            result = squareRoot(num1);
            printf("The square root of %.2lf is: %.2lf", num1, result);
            break;
        case 7:
            printf("Enter two numbers for power:\n");
            scanf("%lf %lf", &num1, &num2);
            result = power(num1, num2);
            printf("%.2lf raised to power %.2lf is: %.2lf", num1, num2, result);
            break;
        default:
            printf("Invalid option selected!");
    }

    return 0;
}


/* Function Definitions */

/* Function to add two numbers */
double add(double num1, double num2) {
    return num1 + num2;
}

/* Function to subtract two numbers */
double subtract(double num1, double num2) {
    return num1 - num2;
}

/* Function to multiply two numbers */
double multiply(double num1, double num2) {
    return num1 * num2;
}

/* Function to divide two numbers */
double divide(double num1, double num2) {
    return num1 / num2;
}

/* Function to find square of a number */
double square(double num) {
    return num * num;
}

/* Function to find square root of a number */
double squareRoot(double num) {
    return sqrt(num);
}

/* Function to find power of a number */
double power(double base, double exponent) {
    return pow(base, exponent);
}