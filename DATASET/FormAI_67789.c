//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    int choice;
    float angle, num, den, result;
    double radian;

    printf("Welcome to the scientific calculator\n");

    do {
        printf("\nChoose an operation:\n");
        printf("1- Addition\n");
        printf("2- Subtraction\n");
        printf("3- Multiplication\n");
        printf("4- Division\n");
        printf("5- Modulus\n");
        printf("6- Power\n");
        printf("7- Square Root\n");
        printf("8- Sine\n");
        printf("9- Cosine\n");
        printf("10- Tangent\n");
        printf("11- Quit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter two numbers to add(separate with a space): ");
                scanf("%f%f", &num, &den);
                result = num + den;
                printf("\n%.2f + %.2f = %.2f\n", num, den, result);
                break;

            case 2:
                printf("\nEnter two numbers to subtract(separate with a space): ");
                scanf("%f%f", &num, &den);
                result = num - den;
                printf("\n%.2f - %.2f = %.2f\n", num, den, result);
                break;

            case 3:
                printf("\nEnter two numbers to multiply(separate with a space): ");
                scanf("%f%f", &num, &den);
                result = num * den;
                printf("\n%.2f * %.2f = %.2f\n", num, den, result);
                break;

            case 4:
                printf("\nEnter two numbers to divide(separate with a space): ");
                scanf("%f%f", &num, &den);

                if (den != 0)
                {
                    result = num / den;
                    printf("\n%.2f / %.2f = %.2f\n", num, den, result);
                }
                else
                {
                    printf("\nError: Division by zero\n");
                }
                break;

            case 5:
                printf("\nEnter two numbers to find remainder(separate with a space): ");
                scanf("%f%f", &num, &den);

                if (den != 0)
                {
                    result = fmod(num, den);
                    printf("\n%.2f mod %.2f = %.2f\n", num, den, result);
                }
                else
                {
                    printf("\nError: Division by zero\n");
                }
                break;

            case 6:
                printf("\nEnter base number: ");
                scanf("%f", &num);
                printf("\nEnter exponent number: ");
                scanf("%f", &den);
                result = pow(num, den);
                printf("\n%.2f ^ %.2f = %.2f\n", num, den, result);
                break;

            case 7:
                printf("\nEnter a number to find square root: ");
                scanf("%f", &num);
                if (num >= 0)
                {
                    result = sqrt(num);
                    printf("\nSquare root of %.2f = %.2f\n", num, result);
                }
                else
                {
                    printf("\nError: Invalid input\n");
                }
                break;

            case 8:
                printf("\nEnter an angle in degrees: ");
                scanf("%f", &angle);
                radian = angle * PI / 180.0;
                result = sin(radian);
                printf("\nSine(%.2f) = %.2f\n", angle, result);
                break;

            case 9:
                printf("\nEnter an angle in degrees: ");
                scanf("%f", &angle);
                radian = angle * PI / 180.0;
                result = cos(radian);
                printf("\nCosine(%.2f) = %.2f\n", angle, result);
                break;

            case 10:
                printf("\nEnter an angle in degrees: ");
                scanf("%f", &angle);
                radian = angle * PI / 180.0;
                result = tan(radian);
                printf("\nTangent(%.2f) = %.2f\n", angle, result);
                break;

            case 11:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nError: Invalid choice\n");
                break;
        }

    } while (choice != 11);

    return 0;
}