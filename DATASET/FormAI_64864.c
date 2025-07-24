//FormAI DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Welcome Message
    printf("Welcome to the Error Handling Program\n\n");

    // Variable Declarations
    int num1, num2, result;

    // Asking for User Input
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Error Handling
    if (num2 == 0) {
        printf("\nError: Division by zero is not allowed!\n");
        exit(1);
    }

    // Performing the Calculation
    result = num1 / num2;

    // Displaying the Result
    printf("\nThe result of %d divided by %d is %d\n", num1, num2, result);

    // End Message
    printf("\nThank you for using the Error Handling Program!\n");

    return 0;
}