//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float num1, num2, result;
    int choice;

    printf("Welcome to Scientific Calculator!\n");

    do {
        printf("\n");
        printf("Please select an operation to perform: \n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exponentiation\n");
        printf("6. Square root\n");
        printf("7. Logarithm\n");
        printf("8. Exit\n\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = num1 + num2;
                printf("Result: %f \n", result);
                break;

            case 2:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = num1 - num2;
                printf("Result: %f \n", result);
                break;

            case 3:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = num1 * num2;
                printf("Result: %f \n", result);
                break;

            case 4:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = num1 / num2;
                printf("Result: %f \n", result);
                break;

            case 5:
                printf("Enter the base number: ");
                scanf("%f", &num1);
                printf("Enter the exponent number: ");
                scanf("%f", &num2);
                result = pow(num1, num2);
                printf("Result: %f \n", result);
                break;

            case 6:
                printf("Enter the number: ");
                scanf("%f", &num1);
                result = sqrt(num1);
                printf("Result: %f \n", result);
                break;

            case 7:
                printf("Enter the number: ");
                scanf("%f", &num1);
                result = log10(num1);
                printf("Result: %f \n", result);
                break;

            case 8:
                printf("Thank you for using Scientific Calculator!\n");
                exit(0);
                break;

            default:
                printf("Invalid input! Please select a valid operation.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}