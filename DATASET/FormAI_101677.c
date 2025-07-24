//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: light-weight
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    float num1, num2;

    printf("Welcome to the Scientific Calculator\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("6. Square Root (√)\n");
    printf("7. Power (^)\n");
    printf("Please choose an option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            break;
        case 5:
            printf("Enter two numbers to find modulus: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f %% %.2f = %.2f\n", num1, num2, fmod(num1, num2));
            break;
        case 6:
            printf("Enter a number to find square root: ");
            scanf("%f", &num1);
            printf("√%.2f = %.2f\n", num1, sqrt(num1));
            break;
        case 7:
            printf("Enter base and exponent: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f ^ %.2f = %.2f", num1, num2, pow(num1, num2));
            break;
        default:
            printf("Invalid option chosen!");
    }

    return 0;
}