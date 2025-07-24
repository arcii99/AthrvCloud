//FormAI DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent a custom error message
typedef struct {
    int error_code;
    char error_message[100];
} custom_error;

// A function to throw a custom error
void throw_custom_error(custom_error *error) {
    printf("An error with code %d occurred: %s\n", error->error_code, error->error_message);
}

int main() {
    // Declare and allocate memory for a custom error
    custom_error *my_error = (custom_error *) malloc(sizeof(custom_error));
    if(my_error == NULL) {
        // Throw a standard out-of-memory error
        printf("An error occurred while allocating memory. Exiting program.\n");
        exit(1);
    }

    // Set some attributes for the custom error
    my_error->error_code = 404;
    strcpy(my_error->error_message, "Page not found");

    // Throw the custom error
    throw_custom_error(my_error);

    // Free the memory allocated for the custom error
    free(my_error);

    return 0;
}