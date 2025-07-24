//FormAI DATASET v1.0 Category: Calculator ; Style: minimalist
#include <stdio.h>

int main() {
    char choice;
    float num1, num2;

    do {
        printf("\nChoose an option: \n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        if (choice == '5') {
            printf("\nExiting Program. Thanks for using the calculator!\n");
            break;
        } else if (choice < '1' || choice > '5') {
            printf("\nInvalid choice. Please try again.\n");
            continue;
        }

        printf("\nEnter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);

        if (choice == '1') {
            printf("\nThe sum of %0.2f and %0.2f is: %0.2f\n", num1, num2, num1 + num2);
        } else if (choice == '2') {
            printf("\nThe difference between %0.2f and %0.2f is: %0.2f\n", num1, num2, num1 - num2);
        } else if (choice == '3') {
            printf("\nThe product of %0.2f and %0.2f is: %0.2f\n", num1, num2, num1 * num2);
        } else if (choice == '4') {
            if (num2 == 0) {
                printf("\nError: Division by zero.\n");
            } else {
                printf("\nThe quotient of %0.2f and %0.2f is: %0.2f\n", num1, num2, num1 / num2);
            }
        }
    } while (1);

    return 0;
}