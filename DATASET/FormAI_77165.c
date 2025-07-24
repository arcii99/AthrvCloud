//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: visionary
#include <stdio.h>
#include <math.h>

int main() {
    float num1, num2, ans;
    int choice;

    printf("*** A Visionary Scientific Calculator Implementation ***\n\n");
    
    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    printf("Choose the operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Logarithm\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            ans = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, ans);
            break;

        case 2:
            ans = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, ans);
            break;

        case 3:
            ans = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, ans);
            break;

        case 4:
            if (num2 != 0) {
                ans = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, ans);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;

        case 5:
            ans = pow(num1, num2);
            printf("%.2f raised to the power of %.2f = %.2f\n", num1, num2, ans);
            break;

        case 6:
            if (num1 >= 0) {
                ans = sqrt(num1);
                printf("Square root of %.2f = %.2f\n", num1, ans);
            } else {
                printf("Error: Square root of negative number!\n");
            }
            break;

        case 7:
            if (num1 > 0) {
                ans = log10(num1);
                printf("Log base 10 of %.2f = %.2f\n", num1, ans);
            } else {
                printf("Error: Logarithm of non-positive number!\n");
            }
            break;

        default:
            printf("Error: Invalid choice!\n");
    }

    return 0;
}