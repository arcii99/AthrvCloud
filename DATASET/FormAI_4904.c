//FormAI DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Creating a custom error handling structure
typedef struct Error {
    bool has_error;
    char message[100];
} Error;

// Function to simulate an asynchronous operation that returns an error
void simulate_async_op(Error* error) {
    int random_error = rand() % 2;
    if (random_error == 0) {
        error->has_error = true;
        sprintf(error->message, "Error: Something went wrong in async operation!");
    }
    else {
        error->has_error = false;
    }
}

// Function to handle and report errors
void handle_error(Error* error) {
    if (error->has_error) {
        printf("Error message: %s\n", error->message);
        exit(EXIT_FAILURE);
    }
}

int main() {
    Error async_error = { false, "" };
    printf("Starting async operation...\n");
    simulate_async_op(&async_error);
    handle_error(&async_error);
    printf("Async operation completed successfully!\n");
    return 0;
}