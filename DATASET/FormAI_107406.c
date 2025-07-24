//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: single-threaded
#include <stdio.h>
#include <math.h>

// Function to return the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main() {
    int choice;
    float num1, num2, result;

    // Main menu
    printf("Welcome to the C Scientific Calculator!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Root\n");
    printf("7. Logarithm\n");
    printf("8. Factorial\n");
    printf("Enter your choice (1-8): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Addition
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("The result is: %.2f", result);
            break;
        case 2:
            // Subtraction
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("The result is: %.2f", result);
            break;
        case 3:
            // Multiplication
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("The result is: %.2f", result);
            break;
        case 4:
            // Division
            printf("Enter the numerator: ");
            scanf("%f", &num1);
            printf("Enter the denominator: ");
            scanf("%f", &num2);
            if (num2 == 0) {
                printf("Error: cannot divide by zero");
            }
            else {
                result = num1 / num2;
                printf("The result is: %.2f", result);
            }
            break;
        case 5:
            // Power
            printf("Enter the base: ");
            scanf("%f", &num1);
            printf("Enter the exponent: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("The result is: %.2f", result);
            break;
        case 6:
            // Root
            printf("Enter the number: ");
            scanf("%f", &num1);
            printf("Enter the degree of the root: ");
            scanf("%f", &num2);
            result = pow(num1, 1/num2);
            printf("The result is: %.2f", result);
            break;
        case 7:
            // Logarithm
            printf("Enter the number: ");
            scanf("%f", &num1);
            result = log(num1);
            printf("The result is: %.2f", result);
            break;
        case 8:
            // Factorial
            printf("Enter the number: ");
            scanf("%f", &num1);
            if (num1 < 0) {
                printf("Error: factorial of a negative number is undefined");
            }
            else {
                result = factorial((int)num1);
                printf("The result is: %.2f", result);
            }
            break;
        default:
            printf("Error: invalid choice");
    }

    return 0;
}