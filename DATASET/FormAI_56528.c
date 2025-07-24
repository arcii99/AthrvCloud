//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice;
    float num1, num2, result;

    printf("Welcome to the scientific calculator.\n");
    printf("Please select an operation.\n\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Squared\n");
    printf("6. Square root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("The result of %.2f + %.2f is: %.2f\n", num1, num2, result);
            break;
        case 2:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("The result of %.2f - %.2f is: %.2f\n", num1, num2, result);
            break;
        case 3:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("The result of %.2f * %.2f is: %.2f\n", num1, num2, result);
            break;
        case 4:
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            if (num2 == 0)
            {
                printf("Cannot divide by zero!\n");
                break;
            }
            result = num1 / num2;
            printf("The result of %.2f / %.2f is: %.2f\n", num1, num2, result);
            break;
        case 5:
            printf("Enter the number to be squared: ");
            scanf("%f", &num1);
            result = pow(num1, 2);
            printf("The result of %.2f squared is: %.2f\n", num1, result);
            break;
        case 6:
            printf("Enter the number to find the square root of: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("The square root of %.2f is: %.2f\n", num1, result);
            break;
        case 7:
            printf("Enter the angle in degrees: ");
            scanf("%f", &num1);
            result = sin(num1 * 3.14159265358979323846 / 180.0);
            printf("The sine of %.2f is: %.2f\n", num1, result);
            break;
        case 8:
            printf("Enter the angle in degrees: ");
            scanf("%f", &num1);
            result = cos(num1 * 3.14159265358979323846 / 180.0);
            printf("The cosine of %.2f is: %.2f\n", num1, result);
            break;
        case 9:
            printf("Enter the angle in degrees: ");
            scanf("%f", &num1);
            if (num1 == 90 || num1 == 270)
            {
                printf("Tangent undefined for %.2f!\n", num1);
                break;
            }
            result = tan(num1 * 3.14159265358979323846 / 180.0);
            printf("The tangent of %.2f is: %.2f\n", num1, result);
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    return 0;
}