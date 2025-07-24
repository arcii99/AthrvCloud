//FormAI DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Function to divide two numbers
int divide(int num1, int num2) {
    if (num2 == 0) {
        errno = EINVAL;
        return -1;
    }
    return (num1 / num2);
}

// Main function
int main() {
    int num1, num2, result;

    // Taking input
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Calling divide function
    result = divide(num1, num2);

    // Checking for errors
    if (result == -1) {
        char *errorMessage;
        switch(errno) {
            case EINVAL:
                errorMessage = "Error: Division by zero is undefined.";
                break;
            default:
                errorMessage = "Error: Unknown error occurred.";
                break;
        }
        
        printf("%s\n", errorMessage);
        exit(EXIT_FAILURE);
    }

    // Printing result
    printf("Result is: %d\n", result);
    return 0;
}