//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int choice;
    double num1, num2, result;

    // User menu
    printf("Welcome to C Scientific Calculator\n");
    printf("---------------------------------\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Power (^)\n");
    printf("6. Square Root (√)\n");
    printf("7. Trigonometric Functions\n");
    printf("8. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Perform corresponding operation
        switch (choice)
        {
        case 1:
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("Result: %lf\n", result);
            break;

        case 2:
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("Result: %lf\n", result);
            break;

        case 3:
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("Result: %lf\n", result);
            break;

        case 4:
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 / num2;
            printf("Result: %lf\n", result);
            break;

        case 5:
            printf("\nEnter base and exponent: ");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("Result: %lf\n", result);
            break;

        case 6:
            printf("\nEnter a number: ");
            scanf("%lf", &num1);
            result = sqrt(num1);
            printf("Result: %lf\n", result);
            break;

        case 7:
            // Trigonometric Functions menu
            printf("\nTrigonometric Functions\n");
            printf("-----------------------\n");
            printf("1. Sine (sin)\n");
            printf("2. Cosine (cos)\n");
            printf("3. Tangent (tan)\n");
            printf("4. Inverse Sine (asin)\n");
            printf("5. Inverse Cosine (acos)\n");
            printf("6. Inverse Tangent (atan)\n");
            printf("7. Back\n");

            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("\nEnter an angle in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * PI / 180);
                printf("Result: %lf\n", result);
                break;

            case 2:
                printf("\nEnter an angle in degrees: ");
                scanf("%lf", &num1);
                result = cos(num1 * PI / 180);
                printf("Result: %lf\n", result);
                break;

            case 3:
                printf("\nEnter an angle in degrees: ");
                scanf("%lf", &num1);
                result = tan(num1 * PI / 180);
                printf("Result: %lf\n", result);
                break;

            case 4:
                printf("\nEnter a value between -1 and 1: ");
                scanf("%lf", &num1);
                result = asin(num1) * 180 / PI;
                printf("Result: %lf degrees\n", result);
                break;

            case 5:
                printf("\nEnter a value between -1 and 1: ");
                scanf("%lf", &num1);
                result = acos(num1) * 180 / PI;
                printf("Result: %lf degrees\n", result);
                break;

            case 6:
                printf("\nEnter a value: ");
                scanf("%lf", &num1);
                result = atan(num1) * 180 / PI;
                printf("Result: %lf degrees\n", result);
                break;

            case 7:
                break;

            default:
                printf("Invalid choice!\n");
                break;
            }
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}