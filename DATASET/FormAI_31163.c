//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float num1, num2, result;
    int choice, power;

    printf("Welcome to the C Scientific Calculator!\n\n");

    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exponentiation\n");
    printf("6. Square Root\n");
    printf("7. Absolute Value\n");
    printf("8. Sine\n");
    printf("9. Cosine\n");
    printf("10. Tangent\n");
    
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Please enter two numbers separated by a space:\n");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("The result of %f + %f is %f\n", num1, num2, result);
            break;
        case 2:
            printf("Please enter two numbers separated by a space:\n");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("The result of %f - %f is %f\n", num1, num2, result);
            break;
        case 3:
            printf("Please enter two numbers separated by a space:\n");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("The result of %f * %f is %f\n", num1, num2, result);
            break;
        case 4:
            printf("Please enter two numbers separated by a space:\n");
            scanf("%f %f", &num1, &num2);
            result = num1 / num2;
            printf("The result of %f / %f is %f\n", num1, num2, result);
            break;
        case 5:
            printf("Please enter a number:\n");
            scanf("%f", &num1);
            printf("Please enter the power:\n");
            scanf("%d", &power);
            result = pow(num1, power);
            printf("The result of %f raised to the power of %d is %f\n", num1, power, result);
            break;
        case 6:
            printf("Please enter a number:\n");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("The square root of %f is %f\n", num1, result);
            break;
        case 7:
            printf("Please enter a number:\n");
            scanf("%f", &num1);
            result = abs(num1);
            printf("The absolute value of %f is %f\n", num1, result);
            break;
        case 8:
            printf("Please enter a number (in degrees):\n");
            scanf("%f", &num1);
            result = sin(num1 * M_PI / 180);
            printf("The sine of %f is %f\n", num1, result);
            break;
        case 9:
            printf("Please enter a number (in degrees):\n");
            scanf("%f", &num1);
            result = cos(num1 * M_PI / 180);
            printf("The cosine of %f is %f\n", num1, result);
            break;
        case 10:
            printf("Please enter a number (in degrees):\n");
            scanf("%f", &num1);
            result = tan(num1 * M_PI / 180);
            printf("The tangent of %f is %f\n", num1, result);
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    return 0;
}