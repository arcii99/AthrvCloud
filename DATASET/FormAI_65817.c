//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shocked
#include <stdio.h>
#include <math.h>

int main()
{
    int choice;
    long double num1, num2, result;

    printf("Welcome to the Scientific Calculator!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Squaring\n6. Square Root\n7. Logarithm\n8. Sine\n9. Cosine\n10. Tangent\n11. Power\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        printf("Enter the first number: ");
        scanf("%Lf", &num1);
        printf("Enter the second number: ");
        scanf("%Lf", &num2);
        result = num1 + num2;
        printf("The result of the operation is: %Lf", result);
        break;

        case 2:
        printf("Enter the first number: ");
        scanf("%Lf", &num1);
        printf("Enter the second number: ");
        scanf("%Lf", &num2);
        result = num1 - num2;
        printf("The result of the operation is: %Lf", result);
        break;

        case 3:
        printf("Enter the first number: ");
        scanf("%Lf", &num1);
        printf("Enter the second number: ");
        scanf("%Lf", &num2);
        result = num1 * num2;
        printf("The result of the operation is: %Lf", result);
        break;

        case 4:
        printf("Enter the first number: ");
        scanf("%Lf", &num1);
        printf("Enter the second number: ");
        scanf("%Lf", &num2);
        result = num1 / num2;
        printf("The result of the operation is: %Lf", result);
        break;

        case 5:
        printf("Enter the number to square: ");
        scanf("%Lf", &num1);
        result = pow(num1, 2);
        printf("The result of the operation is: %Lf", result);
        break;

        case 6:
        printf("Enter the number to find the square root of: ");
        scanf("%Lf", &num1);
        result = sqrt(num1);
        printf("The result of the operation is: %Lf", result);
        break;

        case 7:
        printf("Enter the number to find the logarithm of: ");
        scanf("%Lf", &num1);
        result = log(num1);
        printf("The result of the operation is: %Lf", result);
        break;

        case 8:
        printf("Enter the angle in degrees: ");
        scanf("%Lf", &num1);
        result = sin(num1);
        printf("The result of the operation is: %Lf", result);
        break;

        case 9:
        printf("Enter the angle in degrees: ");
        scanf("%Lf", &num1);
        result = cos(num1);
        printf("The result of the operation is: %Lf", result);
        break;

        case 10:
        printf("Enter the angle in degrees: ");
        scanf("%Lf", &num1);
        result = tan(num1);
        printf("The result of the operation is: %Lf", result);
        break;

        case 11:
        printf("Enter the base: ");
        scanf("%Lf", &num1);
        printf("Enter the exponent: ");
        scanf("%Lf", &num2);
        result = pow(num1, num2);
        printf("The result of the operation is: %Lf", result);
        break;

        default:
        printf("Invalid choice.");
        break;
    }

    return 0;
}