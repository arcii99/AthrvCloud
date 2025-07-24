//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to clear the input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

int main() {
    int choice, num, i;
    float result, base, exponent, angleindeg, angleinrad, num1, num2;

    printf("Welcome to the futuristic scientific calculator!\n\n");

    do {
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square root\n");
        printf("6. Power\n");
        printf("7. Sine\n");
        printf("8. Cosine\n");
        printf("9. Tangent\n");
        printf("10. Logarithm\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of values to be added: ");
                scanf("%d", &num);
                result = 0;
                for (i = 0; i < num; i++) {
                    printf("Enter value #%d: ", i+1);
                    scanf("%f", &num1);
                    result += num1;
                }
                printf("Result: %.2f\n\n", result);
                break;

            case 2:
                printf("Enter first number: ");
                scanf("%f", &num1);
                printf("Enter second number: ");
                scanf("%f", &num2);
                result = num1 - num2;
                printf("Result: %.2f\n\n", result);
                break;

            case 3:
                printf("Enter the number of values to be multiplied: ");
                scanf("%d", &num);
                result = 1;
                for (i = 0; i < num; i++) {
                    printf("Enter value #%d: ", i+1);
                    scanf("%f", &num1);
                    result *= num1;
                }
                printf("Result: %.2f\n\n", result);
                break;

            case 4:
                printf("Enter dividend: ");
                scanf("%f", &num1);
                printf("Enter divisor: ");
                scanf("%f", &num2);
                if (num2 == 0) {
                    printf("Error! Division by zero.\n\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2f\n\n", result);
                }
                break;

            case 5:
                printf("Enter number to find square root of: ");
                scanf("%f", &num1);
                if (num1 < 0) {
                    printf("Error! Square root of negative number is not defined.\n\n");
                } else {
                    result = sqrt(num1);
                    printf("Result: %.2f\n\n", result);
                }
                break;

            case 6:
                printf("Enter base: ");
                scanf("%f", &base);
                printf("Enter exponent: ");
                scanf("%f", &exponent);
                result = pow(base, exponent);
                printf("Result: %.2f\n\n", result);
                break;

            case 7:
                printf("Enter angle in degrees: ");
                scanf("%f", &angleindeg);
                angleinrad = angleindeg * (M_PI / 180.0);
                result = sin(angleinrad);
                printf("Result: %.2f\n\n", result);
                break;

            case 8:
                printf("Enter angle in degrees: ");
                scanf("%f", &angleindeg);
                angleinrad = angleindeg * (M_PI / 180.0);
                result = cos(angleinrad);
                printf("Result: %.2f\n\n", result);
                break;

            case 9:
                printf("Enter angle in degrees: ");
                scanf("%f", &angleindeg);
                angleinrad = angleindeg * (M_PI / 180.0);
                result = tan(angleinrad);
                printf("Result: %.2f\n\n", result);
                break;

            case 10:
                printf("Enter value to find logarithm of: ");
                scanf("%f", &num1);
                if (num1 <= 0) {
                    printf("Error! Logarithm of non-positive number is not defined.\n\n");
                } else {
                    result = log10(num1);
                    printf("Result: %.2f\n\n", result);
                }
                break;

            case 11:
                printf("Thank you for using the futuristic scientific calculator!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n\n");
                break;
        }

        // Clear the input buffer
        clearInputBuffer();

    } while (1);

    return 0;
}