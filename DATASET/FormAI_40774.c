//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice, a, b, i = 1, x = 1;
    float result;

    printf("Welcome to the C Scientific Calculator!\n\n");
    
    while (x) {
        printf("Please choose an option:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square Root\n");
        printf("6. Power\n");
        printf("7. Absolute value\n");
        printf("8. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers to add:\n");
                scanf("%d %d", &a, &b);
                result = a + b;
                printf("Result = %.2f\n\n", result);
                break;
            case 2:
                printf("Enter two numbers to subtract:\n");
                scanf("%d %d", &a, &b);
                result = a - b;
                printf("Result = %.2f\n\n", result);
                break;
            case 3:
                printf("Enter two numbers to multiply:\n");
                scanf("%d %d", &a, &b);
                result = a * b;
                printf("Result = %.2f\n\n", result);
                break;
            case 4:
                printf("Enter two numbers to divide:\n");
                scanf("%d %d", &a, &b);
                result = a / (float) b;
                printf("Result = %.2f\n\n", result);
                break;
            case 5:
                printf("Enter a number to find its square root:\n");
                scanf("%d", &a);
                result = sqrt(a);
                printf("Result = %.2f\n\n", result);
                break;
            case 6:
                printf("Enter two numbers, base and power, respectively:\n");
                scanf("%d %d", &a, &b);
                result = pow(a, b);
                printf("Result = %.2f\n\n", result);
                break;
            case 7:
                printf("Enter a number to find its absolute value:\n");
                scanf("%d", &a);
                result = abs(a);
                printf("Result = %.2f\n\n", result);
                break;
            case 8:
                printf("Thank you for using the C Scientific Calculator. Goodbye!\n");
                x = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
    return 0;
}