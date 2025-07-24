//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice;
    float num1, num2, result;
    printf("Welcome to the Peaceful Scientific Calculator!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Logarithm Base 10\n");
    printf("8. Logarithm Base 2\n");
    printf("9. Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("The result is %f\n", result);
            break;

        case 2:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("The result is %f\n", result);
            break;

        case 3:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("The result is %f\n", result);
            break;

        case 4:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            if(num2 == 0) {
                printf("Invalid input! Division by zero is not allowed.\n");
            }
            else {
                result = num1 / num2;
                printf("The result is %f\n", result);
            }
            break;

        case 5:
            printf("Enter the number: ");
            scanf("%f", &num1);
            printf("Enter the exponent: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("The result is %f\n", result);
            break;

        case 6:
            printf("Enter the number: ");
            scanf("%f", &num1);
            if(num1 < 0) {
                printf("Invalid input! Square root of negative numbers is not defined.\n");
            }
            else {
                result = sqrt(num1);
                printf("The result is %f\n", result);
            }
            break;

        case 7:
            printf("Enter the number: ");
            scanf("%f", &num1);
            if(num1 <= 0) {
                printf("Invalid input! Logarithm of non-positive numbers is not defined.\n");
            }
            else {
                result = log10(num1);
                printf("The result is %f\n", result);
            }
            break;

        case 8:
            printf("Enter the number: ");
            scanf("%f", &num1);
            if(num1 <= 0) {
                printf("Invalid input! Logarithm of non-positive numbers is not defined.\n");
            }
            else {
                result = log2(num1);
                printf("The result is %f\n", result);
            }
            break;

        case 9:
            printf("Thank you for using the Peaceful Scientific Calculator.\n");
            exit(0);

        default:
            printf("Invalid input! Please enter a valid choice.\n");
            break;
    }

    main();
    return 0;
}