//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <math.h>

/* Function declarations */
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double power(double base, double exp);
double squareRoot(double x);
double absolute(double x);
double logBase10(double x);

/* Main function */
int main() {
    int choice;
    double x, y;

    printf("Welcome to C Scientific Calculator Implementation\n");

    do {
        printf("\nChoose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Square Root\n");
        printf("7. Absolute Value\n");
        printf("8. Log Base 10\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        printf("\n");

        switch(choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                printf("Result: %lf\n", add(x, y));
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                printf("Result: %lf\n", subtract(x, y));
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                printf("Result: %lf\n", multiply(x, y));
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                printf("Result: %lf\n", divide(x, y));
                break;
            case 5:
                printf("Enter the base and exponent: ");
                scanf("%lf %lf", &x, &y);
                printf("Result: %lf\n", power(x, y));
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &x);
                printf("Result: %lf\n", squareRoot(x));
                break;
            case 7:
                printf("Enter a number: ");
                scanf("%lf", &x);
                printf("Result: %lf\n", absolute(x));
                break;
            case 8:
                printf("Enter a number: ");
                scanf("%lf", &x);
                printf("Result: %lf\n", logBase10(x));
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice... Try again\n");
        }
    } while(choice != 9);

    return 0;
}

/* Function definitions */

/* Returns the sum of x and y */
double add(double x, double y) {
    return x + y;
}

/* Returns the difference of x and y */
double subtract(double x, double y) {
    return x - y;
}

/* Returns the product of x and y */
double multiply(double x, double y) {
    return x * y;
}

/* Returns the quotient of x and y */
double divide(double x, double y) {
    return x / y;
}

/* Returns the result of raising the base to the exponent */
double power(double base, double exp) {
    return pow(base, exp);
}

/* Returns the square root of x */
double squareRoot(double x) {
    return sqrt(x);
}

/* Returns the absolute value of x */
double absolute(double x) {
    return fabs(x);
}

/* Returns the log base 10 of x */
double logBase10(double x) {
    return log10(x);
}