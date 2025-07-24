//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice;
    float num1, num2,result;

    printf("Welcome to the Scientific Calculator\n");

    do {
        printf("\nChoose an operation:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square root\n7. Logarithm\n8. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter two numbers to add: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                break;

            case 2:
                printf("\nEnter two numbers to subtract: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                break;

            case 3:
                printf("\nEnter two numbers to multiply: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("%.2f * %.2f = %.2f\n", num1, num2, result);
                break;

            case 4:
                printf("\nEnter two numbers to divide: ");
                scanf("%f %f", &num1, &num2);
                if(num2 == 0)
                    printf("Error: Cannot divide by zero\n");
                else {
                    result = num1 / num2;
                    printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;

            case 5:
                printf("\nEnter base number: ");
                scanf("%f", &num1);
                printf("Enter exponent: ");
                scanf("%f", &num2);
                result = pow(num1, num2);
                printf("%.2f^%.2f = %.2f\n", num1, num2, result);
                break;

            case 6:
                printf("\nEnter a number to find square root: ");
                scanf("%f", &num1);
                result = sqrt(num1);
                printf("Square root of %.2f = %.2f\n", num1, result);
                break;

            case 7:
                printf("\nEnter a number to find the natural logarithm: ");
                scanf("%f", &num1);
                result = log(num1);
                printf("Natural logarithm of %.2f = %.2f\n", num1, result);
                break;

            case 8:
                printf("\nExiting...\n");
                exit(0);
                break;

            default:
                printf("Error: Invalid input\n");
        }

    } while(choice != 8);

    return 0;
}