//FormAI DATASET v1.0 Category: Arithmetic ; Style: protected
#include <stdio.h>

int main() {
    // Declare variables
    int num1, num2, result, choice;
    
    // Instructions
    printf("Enter 2 numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Choose an arithmetic operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    // Switch case for arithmetic operations
    switch(choice) {
        case 1:
            result = num1 + num2;
            printf("Result: %d + %d = %d\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result: %d - %d = %d\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result: %d * %d = %d\n", num1, num2, result);
            break;
        case 4:
            // Check for division by zero
            if(num2 == 0) {
                printf("Error: Cannot divide by zero\n");
            } else {
                result = num1 / num2;
                printf("Result: %d / %d = %d\n", num1, num2, result);
            }
            break;
        default:
            printf("Error: Invalid choice. Please choose between 1-4\n");
    }
    return 0;
}