//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int choice;
    float num1, num2, result;
    printf("\n\nWelcome to the Scientific Calculator\n\n");

    do {
        printf("\nPlease select an operation to perform:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square Root\n6. Power\n7. Logarithm\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter two numbers to add: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("\nThe sum of %.2f and %.2f is: %.2f\n", num1, num2, result);
                break;
            case 2: 
                printf("Enter two numbers to subtract: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("\nThe difference of %.2f and %.2f is: %.2f\n", num1, num2, result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("\nThe product of %.2f and %.2f is: %.2f\n", num1, num2, result);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%f %f", &num1, &num2);
                if (num2 == 0) {
                    printf("\nError: Division by zero.\n");
                }
                else {
                    result = num1 / num2;
                    printf("\nThe quotient of %.2f and %.2f is: %.2f\n", num1, num2, result);
                }
                break;
            case 5:
                printf("Enter a number to find the square root of: ");
                scanf("%f", &num1);
                if (num1 < 0) {
                    printf("\nError: Invalid input. Cannot find square root of a negative number.\n");
                }
                else {
                    result = sqrt(num1);
                    printf("\nThe square root of %.2f is: %.2f\n", num1, result);
                }
                break;
            case 6:
                printf("Enter a number and its exponent: ");
                scanf("%f %f", &num1, &num2);
                result = pow(num1,num2);
                printf("\nThe value of %.2f raised to the power of %.2f is: %.2f\n", num1, num2, result);
                break;
            case 7:
                printf("Enter a number to find the natural logarithm of: ");
                scanf("%f", &num1);
                if (num1 <= 0) {
                    printf("\nError: Invalid input. Cannot find natural logarithm of a number that is <= 0.\n");
                }
                else {
                    result = log(num1);
                    printf("\nThe natural logarithm of %.2f is: %.2f\n", num1, result);
                }
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid input. Please try again.\n");
        }

    } while (1);

    return 0;
}