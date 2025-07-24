//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genious
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    float num1, num2, result;
    printf("Welcome to the Genius Scientific Calculator!\n");

    do {
        printf("\nPlease select an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square root\n");
        printf("6. Exponential function\n");
        printf("7. Natural logarithm\n");
        printf("8. Trigonometric functions\n");
        printf("9. Modulus\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%f%f", &num1, &num2);
                result = num1 + num2;
                printf("Sum of %f and %f = %f\n", num1, num2, result);
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%f%f", &num1, &num2);
                result = num1 - num2;
                printf("Difference of %f and %f = %f\n", num1, num2, result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%f%f", &num1, &num2);
                result = num1 * num2;
                printf("Product of %f and %f = %f\n", num1, num2, result);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%f%f", &num1, &num2);
                if(num2 == 0) {
                    printf("Error: Division by 0\n");
                }
                else {
                    result = num1 / num2;
                    printf("Quotient of %f and %f = %f\n", num1, num2, result);
                }
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%f", &num1);
                if(num1 < 0) {
                    printf("Error: Cannot find square root of a negative number\n");
                }
                else {
                    result = sqrt(num1);
                    printf("Square root of %f = %f\n", num1, result);
                }
                break;
            case 6:
                printf("Enter the base value: ");
                scanf("%f", &num1);
                printf("Enter the exponent value: ");
                scanf("%f", &num2);
                result = pow(num1, num2);
                printf("%f raised to the power of %f = %f\n", num1, num2, result);
                break;
            case 7:
                printf("Enter a number: ");
                scanf("%f", &num1);
                if(num1 <= 0) {
                    printf("Error: Cannot find natural logarithm of a non-positive number\n");
                }
                else {
                    result = log(num1);
                    printf("Natural logarithm of %f = %f\n", num1, result);
                }
                break;
            case 8:
                printf("Enter an angle in degrees: ");
                scanf("%f", &num1);
                result = sin(num1 * M_PI/180);
                printf("Sine of %f degrees = %f\n", num1, result);
                result = cos(num1 * M_PI/180);
                printf("Cosine of %f degrees = %f\n", num1, result);
                result = tan(num1 * M_PI/180);
                printf("Tangent of %f degrees = %f\n", num1, result);
                break;
            case 9:
                printf("Enter two numbers to find modulus: ");
                scanf("%f%f", &num1, &num2);
                if(num2 == 0) {
                    printf("Error: Division by 0\n");
                }
                else {
                    result = fmod(num1, num2);
                    printf("Modulus of %f and %f = %f\n", num1, num2, result);
                }
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: Invalid choice\n");
        }

    } while(choice != 0);

    return 0;
}