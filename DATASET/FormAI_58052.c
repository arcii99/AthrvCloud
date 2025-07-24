//FormAI DATASET v1.0 Category: Error handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error codes
#define ERROR_DIVIDE_BY_ZERO 1
#define ERROR_INVALID_ARGUMENTS 2

void customError(int errorCode) {
    switch (errorCode) {
        case ERROR_DIVIDE_BY_ZERO:
            printf("Oh no! You cannot divide by zero. Please try again.\n");
            break;
        case ERROR_INVALID_ARGUMENTS:
            printf("Oops! Looks like you entered invalid arguments. Please try again.\n");
            break;
        default:
            printf("Unknown error occurred. Please try again.\n");
    }
}

int main(int argc, char *argv[]) {
    int x = 10, y = 0, result;
    
    if (argc != 3) {
        customError(ERROR_INVALID_ARGUMENTS); // Invalid number of arguments
        return 1;
    }
    
    // Converting arguments to integers
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    
    // Checking for divide by zero error
    if (y == 0) {
        customError(ERROR_DIVIDE_BY_ZERO); // Division by zero error
        return 1;
    }
    
    result = x / y;
    
    printf("Result: %d\n", result);
    
    return 0;
}