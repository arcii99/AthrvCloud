//FormAI DATASET v1.0 Category: Calculator ; Style: sophisticated
// This is a sophisticated C Calculator program developed by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice;
    double num1, num2, result;

    printf("Welcome to the Sophisticated C Calculator\n");
    printf("========================================\n\n");
    
    do {
        printf("Enter an operation to perform:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square root\n7. Exit\n\n");
        printf("Your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter two numbers to add:\n");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("\n%.2lf + %.2lf = %.2lf\n\n", num1, num2, result);
                break;
            case 2:
                printf("\nEnter two numbers to subtract:\n");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("\n%.2lf - %.2lf = %.2lf\n\n", num1, num2, result);
                break;
            case 3:
                printf("\nEnter two numbers to multiply:\n");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("\n%.2lf * %.2lf = %.2lf\n\n", num1, num2, result);
                break;
            case 4:
                printf("\nEnter two numbers to divide:\n");
                scanf("%lf %lf", &num1, &num2);
                result = num1 / num2;
                if (num2 != 0) {
                    printf("\n%.2lf / %.2lf = %.2lf\n\n", num1, num2, result);
                } else {
                    printf("\nError: Divide by zero\n\n");
                }
                break;
            case 5:
                printf("\nEnter a number and its power:\n");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("\n%.2lf raised to the power of %.2lf = %.2lf\n\n", num1, num2, result);
                break;
            case 6:
                printf("\nEnter a number to get its square root:\n");
                scanf("%lf", &num1);
                if (num1 >= 0) {
                    result = sqrt(num1);
                    printf("\nThe square root of %.2lf is %.2lf\n\n", num1, result);
                } else {
                    printf("\nError: Square root of negative number\n\n");
                }
                break;
            case 7:
                printf("\nThank you for using the Sophisticated C Calculator!\n\n");
                break;
            default:
                printf("\nError: Invalid choice\n\n");
                break;
        }

    } while (choice != 7);

    return 0;
}