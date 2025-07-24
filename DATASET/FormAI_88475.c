//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice;
    float num1, num2, result=0;

    printf("Welcome to Scientific Calculator\n\n");

    while(1) // Loop to allow for multiple calculations
    {
        printf("\nPlease select an operation:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Modulus (%%)\n");
        printf("6. Power (^)\n");
        printf("7. Square root (sqrt)\n");           
        printf("8. Logarithmic (log)\n");
        printf("9. Exponential (exp)\n");
        printf("10. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: // Addition operation
                printf("\nEnter the two numbers to add: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("\nResult: %.2f\n", result);
                break;

            case 2: // Subtraction operation
                printf("\nEnter the two numbers to subtract: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("\nResult: %.2f\n", result);
                break;

            case 3: // Multiplication operation
                printf("\nEnter the two numbers to multiply: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("\nResult: %.2f\n", result);
                break;

            case 4: // Division operation
                printf("\nEnter the two numbers to divide: ");
                scanf("%f %f", &num1, &num2);
                if(num2 == 0)
                {
                    printf("\nError: Cannot divide by zero\n");
                    break;
                }
                result = num1 / num2;
                printf("\nResult: %.2f\n", result);
                break;

            case 5: // Modulus operation
                printf("\nEnter the two numbers to find modulus: ");
                scanf("%f %f", &num1, &num2);
                if(num2 == 0)
                {
                    printf("\nError: Cannot divide by zero\n");
                    break;
                }
                result = fmod(num1, num2);
                printf("\nResult: %.2f\n", result);
                break;

            case 6: // Power operation
                printf("\nEnter the number and the exponent: ");
                scanf("%f %f", &num1, &num2);
                result = pow(num1, num2);
                printf("\nResult: %.2f\n", result);
                break;

            case 7: // Square root operation
                printf("\nEnter the number: ");
                scanf("%f", &num1);
                if(num1 < 0)
                {
                    printf("\nError: Cannot find square root of negative number\n");
                    break;
                }
                result = sqrt(num1);
                printf("\nResult: %.2f\n", result);
                break;

            case 8: // Logarithm operation
                printf("\nEnter the number: ");
                scanf("%f", &num1);
                if(num1 <= 0)
                {
                    printf("\nError: Cannot find logarithm of non-positive number\n");
                    break;
                }
                result = log10(num1);
                printf("\nResult: %.2f\n", result);
                break;

            case 9: // Exponential operation
                printf("\nEnter the number: ");
                scanf("%f", &num1);
                result = exp(num1);
                printf("\nResult: %.2f\n", result);
                break;

            case 10: // Exit operation
                printf("\nExiting the program...\n");
                exit(0);

            default: // Invalid operation
                printf("\nError: Invalid choice\n");
        }
    }

    return 0;
}