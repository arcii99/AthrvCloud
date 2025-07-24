//FormAI DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>

int main() {

    int num1, num2, result;
    
    printf("Enter the first number: ");
    if (scanf("%d", &num1) != 1) {
        printf("Error: Invalid input!\n"); // Error message for invalid input
        return 1; // Exit with error code 1
    }
    
    printf("Enter the second number: ");
    if (scanf("%d", &num2) != 1) {
        printf("Error: Invalid input!\n"); // Error message for invalid input
        return 1; // Exit with error code 1
    }
    
    if (num2 == 0) {
        printf("Error: Division by zero!\n"); // Error message for division by zero
        return 1; // Exit with error code 1
    }
    
    result = num1 / num2; // Divide the two numbers
    
    printf("%d / %d = %d\n", num1, num2, result); // Print the result
    
    return 0; // Exit with success code 0
}