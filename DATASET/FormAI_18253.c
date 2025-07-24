//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice;
    double num1, num2, result;

    printf("Welcome to the Scientific Calculator\n");
    printf("Please choose an operation to perform:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Square Root (√)\n");
    printf("6. Power (^)\n");
    printf("7. Sine (sin)\n");
    printf("8. Cosine (cos)\n");
    printf("9. Tangent (tan)\n");
    printf("Enter your choice (1-9): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("%lf + %lf = %lf\n", num1, num2, result);
            break;
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("%lf - %lf = %lf\n", num1, num2, result);
            break;
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("%lf * %lf = %lf\n", num1, num2, result);
            break;
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 / num2;
            printf("%lf / %lf = %lf\n", num1, num2, result);
            break;
        case 5:
            printf("Enter a number to find its square root: ");
            scanf("%lf", &num1);
            result = sqrt(num1);
            printf("√%lf = %lf\n", num1, result);
            break;
        case 6:
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("%lf ^ %lf = %lf\n", num1, num2, result);
            break;
        case 7:
            printf("Enter an angle in degrees: ");
            scanf("%lf", &num1);
            result = sin(num1 * M_PI / 180);
            printf("sin(%lf) = %lf\n", num1, result);
            break;
        case 8:
            printf("Enter an angle in degrees: ");
            scanf("%lf", &num1);
            result = cos(num1 * M_PI / 180);
            printf("cos(%lf) = %lf\n", num1, result);
            break;
        case 9:
            printf("Enter an angle in degrees: ");
            scanf("%lf", &num1);
            result = tan(num1 * M_PI / 180);
            printf("tan(%lf) = %lf\n", num1, result);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}