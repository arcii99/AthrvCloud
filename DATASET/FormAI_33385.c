//FormAI DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Define a custom error type with an error code and a message string
typedef struct {
    int code;
    char *message;
} error_t;

// Define some custom error codes and messages
#define ERR_NULL_POINTER 1
#define ERR_OUT_OF_MEMORY 2
#define ERR_INVALID_ARGUMENT 3

error_t *create_error(int code, char *message) {
    error_t *error = malloc(sizeof(error_t));
    if (!error) {
        // If malloc fails, set errno and return a null pointer
        errno = ENOMEM;
        return NULL;
    }
    error->code = code;
    error->message = message;
    return error;
}

void destroy_error(error_t *error) {
    if (error) {
        free(error->message);
        free(error);
    }
}

void handle_error(error_t *error) {
    if (!error) {
        // If the error is null, assume it was handled already
        return;
    }
    switch (error->code) {
        case ERR_NULL_POINTER:
            fprintf(stderr, "Error: Null pointer encountered\n");
            break;
        case ERR_OUT_OF_MEMORY:
            fprintf(stderr, "Error: Out of memory\n");
            break;
        case ERR_INVALID_ARGUMENT:
            fprintf(stderr, "Error: Invalid argument\n");
            break;
        default:
            fprintf(stderr, "Error: Unknown error code %d\n", error->code);
            break;
    }
    destroy_error(error);
}

int add(int a, int b, error_t **error) {
    if (!error) {
        // If error is null, assume the caller doesn't care about errors
        return a + b;
    }
    if (!error) {
        // If either a or b is null, set an error and return zero
        *error = create_error(ERR_NULL_POINTER, "Null pointer encountered");
        return 0;
    }
    int result = a + b;
    if ((a > 0 && b > 0 && result <= 0) || (a < 0 && b < 0 && result >= 0)) {
        // If integer overflow occurred, set an error and return zero
        *error = create_error(ERR_OUT_OF_MEMORY, "Out of memory");
        return 0;
    }
    return result;
}

int main() {
    int a = 2, b = 3;
    error_t *error = NULL;
    int result = add(a, b, &error);
    if (error) {
        handle_error(error);
        return 1;
    }
    printf("%d + %d = %d\n", a, b, result);
    return 0;
}