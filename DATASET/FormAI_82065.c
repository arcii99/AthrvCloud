//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: intelligent
#include <stdio.h>
#include <math.h>

int main()
{
    int num1, num2, choice;
    float result;

    printf("Welcome to Intelligent Scientific Calculator\n");
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("\n1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Power\n");
    printf("7. Logarithm\n");
    printf("8. Sine\n");
    printf("9. Cosine\n");
    printf("10. Tangent\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            result = num1 + num2;
            printf("\n%d + %d = %.2f\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("\n%d - %d = %.2f\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("\n%d x %d = %.2f\n", num1, num2, result);
            break;
        case 4:
            result = (float)num1 / num2;
            printf("\n%d / %d = %.2f\n", num1, num2, result);
            break;
        case 5:
            result = sqrt(num1);
            printf("\nSquare root of %d = %.2f\n", num1, result);
            result = sqrt(num2);
            printf("Square root of %d = %.2f\n", num2, result);
            break;
        case 6:
            result = pow(num1, num2);
            printf("\n%d to the power of %d = %.2f\n", num1, num2, result);
            break;
        case 7:
            result = log(num1);
            printf("\nLogarithm of %d = %.2f\n", num1, result);
            result = log(num2);
            printf("Logarithm of %d = %.2f\n", num2, result);
            break;
        case 8:
            result = sin(num1*3.14159/180);
            printf("\nSine of %d degrees = %.2f\n", num1, result);
            result = sin(num2*3.14159/180);
            printf("Sine of %d degrees = %.2f\n", num2, result);
            break;
        case 9:
            result = cos(num1*3.14159/180);
            printf("\nCosine of %d degrees = %.2f\n", num1, result);
            result = cos(num2*3.14159/180);
            printf("Cosine of %d degrees = %.2f\n", num2, result);
            break;
        case 10:
            result = tan(num1*3.14159/180);
            printf("\nTangent of %d degrees = %.2f\n", num1, result);
            result = tan(num2*3.14159/180);
            printf("Tangent of %d degrees = %.2f\n", num2, result);
            break;
        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}