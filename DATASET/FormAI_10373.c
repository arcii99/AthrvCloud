//FormAI DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h> // Standard Input/Output library
#include <stdlib.h> // Standard Library
#include <setjmp.h> // setjmp() and longjmp() functions

// Jump buffer
static jmp_buf error_env;

// Custom error handling function
void throw_error(char* error_message, int error_code) {
    fprintf(stderr, "[ERROR] %s (Error Code: %d)\n", error_message, error_code);
    longjmp(error_env, error_code);
}

int main() {
    // Example code that could potentially raise errors
    int num1, num2, result;
    
    // Set jump point for error handling
    if (setjmp(error_env)) {
        fprintf(stderr, "[INFO] Program ended due to an error.\n");
        return EXIT_FAILURE;
    }

    // Prompt user for input
    printf("Enter two numbers to add: ");
    scanf("%d %d", &num1, &num2);

    // Check for potential errors
    if (num1 < 0) {
        throw_error("First number cannot be negative.", 1);
    }
    if (num2 < 0) {
        throw_error("Second number cannot be negative.", 2);
    }

    // Perform the calculation
    result = num1 + num2;
    printf("Result: %d\n", result);

    // End the program successfully
    return EXIT_SUCCESS;
}