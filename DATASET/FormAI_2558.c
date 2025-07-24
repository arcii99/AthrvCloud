//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    float num1, num2, result;

    printf("\nWelcome to the Scientific Calculator\n");
    printf("------------------------------------\n");
    printf("Please select the operation you want to perform:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exponentiation\n6. Square Root\n7. Logarithm\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Please enter the first number: ");
            scanf("%f", &num1);
            printf("Please enter the second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("The result of %.2f + %.2f is %.2f", num1, num2, result);
            break;
        case 2:
            printf("Please enter the first number: ");
            scanf("%f", &num1);
            printf("Please enter the second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("The result of %.2f - %.2f is %.2f", num1, num2, result);
            break;
        case 3:
            printf("Please enter the first number: ");
            scanf("%f", &num1);
            printf("Please enter the second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("The result of %.2f * %.2f is %.2f", num1, num2, result);
            break;
        case 4:
            printf("Please enter the first number: ");
            scanf("%f", &num1);
            printf("Please enter the second number: ");
            scanf("%f", &num2);
            if (num2 == 0) {
                printf("Error: Cannot divide by zero");
            } else {
                result = num1 / num2;
                printf("The result of %.2f / %.2f is %.2f", num1, num2, result);
            }
            break;
        case 5:
            printf("Please enter the base number: ");
            scanf("%f", &num1);
            printf("Please enter the exponent number: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("%f raised to the power of %f is %f", num1, num2, result);
            break;
        case 6:
            printf("Please enter the number you want to calculate the square root for: ");
            scanf("%f", &num1);
            if (num1 < 0) {
                printf("Error: Cannot calculate square root of negative numbers");
            } else {
                result = sqrt(num1);
                printf("The square root of %.2f is %.2f", num1, result);
            }
            break;
        case 7:
            printf("Please enter the number you want to calculate the logarithm for: ");
            scanf("%f", &num1);
            if (num1 <= 0) {
                printf("Error: Logarithm domain error");
            } else {
                result = log10(num1);
                printf("The logarithm of %.2f is %.2f", num1, result);
            }
            break;
        default:
            printf("Invalid choice");
            break;
    }

    return 0;
}