//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {
    int choice, i = 0;
    double num1, num2, result;

    printf("Welcome to my Scientific Calculator in C!\n");
    printf("\nSelect the operation you want to perform:\n");
    printf("1. Addition(+)\n");
    printf("2. Subtraction(-)\n");
    printf("3. Multiplication(*)\n");
    printf("4. Division(/)\n");
    printf("5. Power(^)\n");
    printf("6. Square Root(sqrt)\n");
    printf("7. Sine(sin)\n");
    printf("8. Cosine(cos)\n");
    printf("9. Tangent(tan)\n");
    printf("10. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter two numbers to add: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("Result: %lf\n", result);
                break;
            case 2:
                printf("\nEnter two numbers to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("Result: %lf\n", result);
                break;
            case 3:
                printf("\nEnter two numbers to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("Result: %lf\n", result);
                break;
            case 4:
                printf("\nEnter two numbers to divide: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 / num2;
                printf("Result: %lf\n", result);
                break;
            case 5:
                printf("\nEnter a number and power to be raised to: ");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 6:
                printf("\nEnter a number to find its square root: ");
                scanf("%lf", &num1);
                result = sqrt(num1);
                printf("Result: %lf\n", result);         
                break;
            case 7:
                printf("\nEnter angle in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * PI / 180);
                printf("Result: %lf\n", result);
                break;
            case 8:
                printf("\nEnter angle in degrees: ");
                scanf("%lf", &num1);
                result = cos(num1 * PI / 180);
                printf("Result: %lf\n", result);
                break;
            case 9:
                printf("\nEnter angle in degrees: ");
                scanf("%lf", &num1);
                result = tan(num1 * PI / 180);
                printf("Result: %lf\n", result);
                break;
            case 10:
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n");
        }
        i++;
    } while (i < 10);

    return 0;
}