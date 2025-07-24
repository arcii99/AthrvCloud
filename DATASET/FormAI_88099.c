//FormAI DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, choice, result;
    printf("Enter the values of a and b:\n");
    scanf("%d %d", &a, &b);

    printf("Menu:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter your choice:");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = a + b;
            printf("Addition of %d and %d is: %d", a, b, result);
            break;

        case 2:
            result = a - b;
            printf("Subtraction of %d and %d is: %d", a, b, result);
            break;

        case 3:
            result = a * b;
            printf("Multiplication of %d and %d is: %d", a, b, result);
            break;

        case 4:
            if (b == 0) {
                printf("Denominator cannot be 0");
            }
            else {
                result = a / b;
                printf("Division of %d and %d is: %d", a, b, result);
            }
            break;

        default:
            printf("Invalid choice entered");
            break;
    }

    return 0;
}