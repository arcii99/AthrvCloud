//FormAI DATASET v1.0 Category: Calculator ; Style: thoughtful
#include <stdio.h>

int main() {

    int num1, num2, sum, sub, mul, choice;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("\nChoose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sum = num1 + num2;
            printf("\n%d + %d = %d\n", num1, num2, sum);
            break;
        case 2:
            sub = num1 - num2;
            printf("\n%d - %d = %d\n", num1, num2, sub);
            break;
        case 3:
            mul = num1 * num2;
            printf("\n%d x %d = %d\n", num1, num2, mul);
            break;
        default:
            printf("\nYou have entered an invalid choice!\n");
            break;
    }

    return 0;
}