//FormAI DATASET v1.0 Category: Math exercise ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    // Declare Variables
    int num1, num2, operation;
    float result;

    // Welcome Message
    printf("Welcome to the Math Exercise Program!\n");

    // Get First Number
    printf("Please enter the first number: ");
    scanf("%d", &num1);

    // Get Second Number
    printf("Please enter the second number: ");
    scanf("%d", &num2);

    // Get Operation
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exponent\n");
    printf("6. Square Root\n");
    printf("Enter operation number: ");
    scanf("%d", &operation);

    // Perform Operation and Print Result
    switch (operation)
    {
        case 1:
            result = num1 + num2;
            printf("The result of %d + %d is %.2f\n", num1, num2, result);
            break;

        case 2:
            result = num1 - num2;
            printf("The result of %d - %d is %.2f\n", num1, num2, result);
            break;

        case 3:
            result = num1 * num2;
            printf("The result of %d * %d is %.2f\n", num1, num2, result);
            break;

        case 4:
            result = num1 / num2;
            printf("The result of %d / %d is %.2f\n", num1, num2, result);
            break;

        case 5:
            result = pow(num1, num2);
            printf("The result of %d to the power of %d is %.2f\n", num1, num2, result);
            break;

        case 6:
            result = sqrt(num1);
            printf("The square root of %d is %.2f\n", num1, result);
            result = sqrt(num2);
            printf("The square root of %d is %.2f\n", num2, result);
            break;

        default:
            printf("Invalid operation number!\n");
    }

    // Goodbye Message
    printf("Thank you for using the Math Exercise Program!\n");

    return 0;
}