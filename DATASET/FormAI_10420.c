//FormAI DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>

int main() {
    int num1, num2, result;

    printf("Enter the first number: ");
    if (scanf("%d", &num1) != 1) {
        printf("Invalid input! Please enter a number.\n");
        return 1;
    }

    printf("Enter the second number: ");
    if (scanf("%d", &num2) != 1) {
        printf("Invalid input! Please enter a number.\n");
        return 1;
    }

    if (num2 == 0) {
        printf("Error: Division by zero!\n");
        return 1;
    }

    result = num1 / num2;

    printf("The result of %d divided by %d is %d\n", num1, num2, result);

    return 0;
}