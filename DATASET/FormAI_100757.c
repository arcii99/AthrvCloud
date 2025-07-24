//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main()
{
    int choice;
    float num1, num2, result;

    printf("Select operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Sine\n");
    printf("7. Cosine\n");
    printf("8. Tangent\n");
    printf("9. Square Root\n");
    printf("10. Power\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("Result: %.2f", result);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("Result: %.2f", result);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("Result: %.2f", result);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 / num2;
            printf("Result: %.2f", result);
            break;
        case 5:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = fmod(num1, num2);
            printf("Result: %.2f", result);
            break;
        case 6:
            printf("Enter a number in radians: ");
            scanf("%f", &num1);
            result = sin(num1);
            printf("Result: %.2f", result);
            break;
        case 7:
            printf("Enter a number in radians: ");
            scanf("%f", &num1);
            result = cos(num1);
            printf("Result: %.2f", result);
            break;
        case 8:
            printf("Enter a number in radians: ");
            scanf("%f", &num1);
            result = tan(num1);
            printf("Result: %.2f", result);
            break;
        case 9:
            printf("Enter a positive number: ");
            scanf("%f", &num1);
            if (num1 < 0)
            {
                printf("Invalid input!");
                return 0;
            }
            result = sqrt(num1);
            printf("Result: %.2f", result);
            break;
        case 10:
            printf("Enter the base: ");
            scanf("%f", &num1);
            printf("Enter the exponent: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("Result: %.2f", result);
            break;
        default:
            printf("Invalid input!");
    }

    return 0;
}