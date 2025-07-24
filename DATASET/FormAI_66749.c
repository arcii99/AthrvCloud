//FormAI DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num1, num2, operation, result;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("\nChoose operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("\nEnter operation number: ");
    scanf("%d", &operation);

    switch (operation) {
        case 1:
            result = num1 + num2;
            printf("\nResult: %d + %d = %d", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("\nResult: %d - %d = %d", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("\nResult: %d * %d = %d", num1, num2, result);
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf("\nResult: %d / %d = %d", num1, num2, result);
            }
            else {
                printf("\nError: Cannot divide by zero");
            }
            break;
        default:
            printf("\nError: Invalid operation number");
    }

    printf("\n\n");

    return 0;
}