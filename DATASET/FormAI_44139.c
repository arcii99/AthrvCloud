//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: invasive
#include <stdio.h>
#include <math.h>

int main() {
    int choice, a, b;
    printf("Welcome to Invasive Scientific Calculator\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square root\n");
    printf("7. Logarithm\n");
    printf("8. Sine\n");
    printf("9. Cosine\n");
    printf("10. Tangent\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);

        int sum = a + b;
        printf("Sum of %d and %d is: %d\n", a, b, sum);
    } else if (choice == 2) {
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);

        int difference = a - b;
        printf("Difference of %d and %d is: %d\n", a, b, difference);
    } else if (choice == 3) {
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);

        int product = a * b;
        printf("Product of %d and %d is: %d\n", a, b, product);
    } else if (choice == 4) {
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);

        int quotient = a / b;
        printf("Quotient of %d and %d is: %d\n", a, b, quotient);
    } else if (choice == 5) {
        printf("Enter base: ");
        scanf("%d", &a);
        printf("Enter exponent: ");
        scanf("%d", &b);

        int result = pow(a, b);
        printf("%d raised to the power of %d is: %d\n", a, b, result);
    } else if (choice == 6) {
        printf("Enter number: ");
        scanf("%d", &a);

        float result = sqrt(a);
        printf("Square root of %d is: %f\n", a, result);
    } else if (choice == 7) {
        printf("Enter number: ");
        scanf("%d", &a);

        float result = log10(a);
        printf("Logarithm of %d is: %f\n", a, result);
    } else if (choice == 8) {
        printf("Enter angle in degrees: ");
        scanf("%d", &a);

        float result = sin(a * 3.14159 / 180);
        printf("Sine of %d degrees is: %f\n", a, result);
    } else if (choice == 9) {
        printf("Enter angle in degrees: ");
        scanf("%d", &a);

        float result = cos(a * 3.14159 / 180);
        printf("Cosine of %d degrees is: %f\n", a, result);
    } else if (choice == 10) {
        printf("Enter angle in degrees: ");
        scanf("%d", &a);

        float result = tan(a * 3.14159 / 180);
        printf("Tangent of %d degrees is: %f\n", a, result);
    } else {
        printf("Invalid choice, please choose a number between 1 and 10\n");
    }

    return 0;
}