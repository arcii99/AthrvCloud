//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: imaginative
#include <stdio.h>
#include <math.h>

int main()
{
    int choice, num1, num2, result, num3, num4;
    float fresult, fnum1, fnum2;

    printf("\n  ---------------------");
    printf("\n | SCIENTIFIC CALCULATOR|");
    printf("\n  ---------------------\n");

    printf("\nEnter your choice: ");
    printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division");
    printf("\n5. Square root\n6. Cube root\n7. Exponentiation\n8. Logarithm");
    printf("\n9. Sine\n10. Cosine\n11. Tangent\n12. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1: // Addition
            printf("\nEnter first number: ");
            scanf("%d", &num1);

            printf("\nEnter second number: ");
            scanf("%d", &num2);

            result = num1 + num2;

            printf("\nThe sum of %d and %d is %d.\n", num1, num2, result);
            break;

        case 2: // Subtraction
            printf("\nEnter first number: ");
            scanf("%d", &num1);

            printf("\nEnter second number: ");
            scanf("%d", &num2);

            result = num1 - num2;

            printf("\nThe difference between %d and %d is %d.\n", num1, num2, result);
            break;

        case 3: // Multiplication
            printf("\nEnter first number: ");
            scanf("%d", &num1);

            printf("\nEnter second number: ");
            scanf("%d", &num2);

            result = num1 * num2;

            printf("\nThe product of %d and %d is %d.\n", num1, num2, result);
            break;

        case 4: // Division
            printf("\nEnter first number: ");
            scanf("%d", &num1);

            printf("\nEnter second number: ");
            scanf("%d", &num2);

            result = num1 / num2;

            printf("\nThe quotient of %d and %d is %d.\n", num1, num2, result);
            break;

        case 5: // Square root
            printf("\nEnter a number: ");
            scanf("%d", &num1);

            fnum1 = sqrt(num1);

            printf("\nThe square root of %d is %.2f.", num1, fnum1);
            break;

        case 6: // Cube root
            printf("\nEnter a number: ");
            scanf("%d", &num1);

            fnum1 = cbrt(num1);

            printf("\nThe cube root of %d is %.2f.", num1, fnum1);
            break;

        case 7: // Exponentiation
            printf("\nEnter a number: ");
            scanf("%d", &num1);

            printf("\nEnter an exponent: ");
            scanf("%d", &num2);

            result = pow(num1, num2);

            printf("\nThe result of %d raised to the power of %d is %d.\n", num1, num2, result);
            break;

        case 8: // Logarithm
            printf("\nEnter a number: ");
            scanf("%d", &num1);

            fnum1 = log10(num1);

            printf("\nThe logarithm of %d is %.2f.", num1, fnum1);
            break;

        case 9: // Sine
            printf("\nEnter an angle in degrees: ");
            scanf("%d", &num1);

            fnum1 = sin(num1 * 3.14159 / 180);

            printf("\nThe sine of %d degrees is %.2f.", num1, fnum1);
            break;

        case 10: // Cosine
            printf("\nEnter an angle in degrees: ");
            scanf("%d", &num1);

            fnum1 = cos(num1 * 3.14159 / 180);

            printf("\nThe cosine of %d degrees is %.2f.", num1, fnum1);
            break;

        case 11: // Tangent
            printf("\nEnter an angle in degrees: ");
            scanf("%d", &num1);

            fnum1 = tan(num1 * 3.14159 / 180);

            printf("\nThe tangent of %d degrees is %.2f.", num1, fnum1);
            break;

        case 12: // Exit
            printf("\nGoodbye!");
            break;

        default: // Invalid input
            printf("\nError: Invalid input");
            break;
    }

    return 0;
}