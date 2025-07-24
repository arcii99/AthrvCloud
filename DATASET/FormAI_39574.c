//FormAI DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Custom error message
#define ERROR_MSG(format, ...) do { fprintf(stderr, "[%s:%d] " format, __FILE__, __LINE__, ##__VA_ARGS__); } while(0)

// Function that may fail and returns an int
int some_function(int x) {
    if (x < 0) {
        ERROR_MSG("x should be non-negative\n");
        return -1;
    }
    return x + 1;
}

int main() {
    int result = some_function(5); // call some_function with non-negative input
    if (result == -1) { // check if some_function failed
        ERROR_MSG("some_function failed\n");
        exit(EXIT_FAILURE); // exit the program with a failure code
    }

    printf("Result: %d\n", result);

    result = some_function(-2); // call some_function with negative input
    if (result == -1) { // check if some_function failed
        ERROR_MSG("some_function failed\n");
        exit(EXIT_FAILURE); // exit the program with a failure code
    }

    printf("Result: %d\n", result);

    return 0;
}