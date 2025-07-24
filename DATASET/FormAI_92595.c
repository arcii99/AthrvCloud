//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: statistical
#include <stdio.h>
#include <math.h>

// Function to find the factorial of a number
int factorial(int n) {
    int fact = 1, i;
    for (i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to find the power of a number
double power(double base, double exponent) {
    return pow(base, exponent);
}

// Function to find the square root of a number
double squareRoot(double num) {
    return sqrt(num);
}

int main() {
    int choice, factNum;
    double num1, num2, result;

    printf("Choose from the following options:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Factorial\n");
    printf("6. Power\n");
    printf("7. Square Root\n");
    printf("8. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 5:
                printf("\nEnter a number: ");
                scanf("%d", &factNum);
                result = factorial(factNum);
                printf("%d! = %.2lf\n", factNum, result);
                break;

            case 6:
                printf("\nEnter the base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 7:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                result = squareRoot(num1);
                printf("sqrt(%.2lf) = %.2lf\n", num1, result);
                break;

            case 8:
                printf("Thank you for using the calculator!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}