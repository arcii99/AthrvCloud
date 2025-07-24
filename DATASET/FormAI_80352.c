//FormAI DATASET v1.0 Category: Error handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define an error structure
typedef struct {
    int code;
    char *message;
} Error;

// Function to generate errors
Error* generate_error(int code, char *err_msg) {
    Error *err = (Error*) malloc(sizeof(Error));
    err->code = code;
    err->message = err_msg;

    return err;
}

// Function to handle errors
void handle_error(Error *err) {
    printf("Error Code: %d\nError Message: %s\n", err->code, err->message);
    free(err); // free up memory allocated for the error
}

// Function to calculate the sum of two numbers
int add(int num1, int num2) {
    if (num1 < 0 || num2 < 0) {
        return generate_error(1, "Cannot add negative numbers."); // generate error
    }

    return num1 + num2;
}

// Main function to test error handling
int main() {
    int num1 = 5, num2 = -8;

    int sum = add(num1, num2);

    if (sum >= 0) {
        printf("The sum of %d and %d is %d\n", num1, num2, sum);
    } else {
        handle_error(sum); // handle error
    }

    return 0;
}