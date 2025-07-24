//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the Mind-Bending Scientific Calculator!");
    printf("\n\n");

    float num1, num2;
    int choice;

    do {
        printf("Please select an option:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square Root\n");
        printf("6. Exponent\n");
        printf("7. Logarithm\n");
        printf("8. Trigonometric Functions\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                if (num2 == 0) {
                    printf("Cannot divide by zero!\n");
                } else {
                    printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
                }
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%f", &num1);
                if (num1 < 0) {
                    printf("Cannot take square root of a negative number!\n");
                } else {
                    printf("Sqrt(%.2f) = %.2f\n", num1, sqrt(num1));
                }
                break;
            case 6:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                printf("%.2f ^ %.2f = %.2f\n", num1, num2, pow(num1, num2));
                break;
            case 7:
                printf("Enter a number: ");
                scanf("%f", &num1);
                if (num1 <= 0) {
                    printf("Logarithm of a non-positive number is undefined!\n");
                } else {
                    printf("Log(%.2f) = %.2f\n", num1, log(num1));
                }
                break;
            case 8:
                printf("Enter a number (in degrees): ");
                scanf("%f", &num1);
                printf("Sin(%.2f) = %.2f\n", num1, sin(num1 * (M_PI / 180)));
                printf("Cos(%.2f) = %.2f\n", num1, cos(num1 * (M_PI / 180)));
                printf("Tan(%.2f) = %.2f\n", num1, tan(num1 * (M_PI / 180)));
                break;
            case 9:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\n");

    } while (choice != 9);

    return 0;
}