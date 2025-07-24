//FormAI DATASET v1.0 Category: Error handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// define an error handler function
void handleError(const char* file, const int line, const char* message) {
    fprintf(stderr, "Error in file %s at line %d: %s\n", file, line, message);
    exit(EXIT_FAILURE);
}

// define a function that might cause an error
int division(int a, int b) {
    if (b == 0) {
        char errorMessage[100];
        snprintf(errorMessage, 100, "Cannot divide by zero! (%d/%d)", a, b);
        handleError(__FILE__, __LINE__, errorMessage);
    }
    return a / b;
}

int main() {
    int a, b, result;
    char buffer[10];

    printf("Enter a numerator: ");
    fgets(buffer, 10, stdin);
    a = strtol(buffer, NULL, 10);

    printf("Enter a denominator: ");
    fgets(buffer, 10, stdin);
    b = strtol(buffer, NULL, 10);

    // call the division function
    result = division(a, b);

    printf("The result of the division is %d\n", result);

    return EXIT_SUCCESS;
}