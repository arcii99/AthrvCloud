//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

/* Define an error handler function */
void error_handler(char* function_name, char* error_message, int error_code) {
    fprintf(stderr, "ERROR in function %s:\n%s\nError code: %d\n", function_name, error_message, error_code);
    exit(error_code);
}

/* Define a function that will perform some operation that can throw an error */
int some_operation(int arg1, int arg2) {
    if (arg1 <= 0 || arg2 <= 0) {
        /* Handle the error */
        error_handler("some_operation", "Invalid arguments.", -1);
    }
    /* Perform the operation */
    int result = arg1 + arg2;
    return result;
}

int main() {
    int arg1 = 5;
    int arg2 = -2;
    int result;

    /* Call the function and catch any errors */
    printf("Performing operation with arguments %d and %d...\n", arg1, arg2);
    result = some_operation(arg1, arg2);
    printf("Operation successful. Result: %d\n", result);

    /* Try a different set of arguments */
    arg1 = 0;
    arg2 = 3;
    printf("\nPerforming operation with arguments %d and %d...\n", arg1, arg2);
    result = some_operation(arg1, arg2);
    printf("Operation successful. Result: %d\n", result);

    return 0;
}