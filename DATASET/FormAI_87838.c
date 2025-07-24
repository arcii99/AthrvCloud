//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    DIVIDE_BY_ZERO,
    OUT_OF_BOUNDS,
    INVALID_ARGUMENT
} ErrorType;

void handleError(ErrorType type, const char* message) {
    switch (type) {
        case DIVIDE_BY_ZERO:
            fprintf(stderr, "ERROR: Attempt to divide by zero. Message: %s\n", message);
            exit(EXIT_FAILURE);
        case OUT_OF_BOUNDS:
            fprintf(stderr, "ERROR: Index out of bounds. Message: %s\n", message);
            exit(EXIT_FAILURE);
        case INVALID_ARGUMENT:
            fprintf(stderr, "ERROR: Invalid argument. Message: %s\n", message);
            exit(EXIT_FAILURE);
        default:
            fprintf(stderr, "ERROR: Unknown error type. Message: %s\n", message);
            exit(EXIT_FAILURE);
    }
}

double divide(double dividend, double divisor) {
    if (divisor == 0.0) {
        handleError(DIVIDE_BY_ZERO, "Error testing divide by zero.");
    }
    return dividend / divisor;
}

int getElement(int* array, int size, int index) {
    if (index < 0 || index >= size) {
        handleError(OUT_OF_BOUNDS, "Error testing index out of bounds.");
    }
    return array[index];
}

void performTask(int arg1, int arg2, int arg3, int arg4) {
    if (arg1 < 0 || arg2 > 100 || arg3 < -50 || arg4 > 50) {
        handleError(INVALID_ARGUMENT, "Error testing invalid argument.");
    }
    // Do something useful...
}

int main() {
    double result = divide(10.0, 0.0);
    int array[] = {1, 2, 3, 4, 5};
    int element = getElement(array, 5, 6);
    performTask(10, 200, -60, 60);

    return EXIT_SUCCESS;
}