//FormAI DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int dividend = 20;
    int divisor = 0;
    int quotient;

    // Handling division by zero error
    if(divisor == 0) {
        printf("Error: Division by zero exception!\n");
        exit(EXIT_FAILURE);
    }

    quotient = dividend / divisor;

    printf("Quotient = %d\n", quotient);

    // Creating and handling a custom error
    int errorCode = 404;
    char* errorMessage = "File not found";
    errno = errorCode;

    fprintf(stderr, "Error %d: %s\n", errno, errorMessage);

    return 0;
}