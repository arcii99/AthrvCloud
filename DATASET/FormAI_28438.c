//FormAI DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void handle_error(const char* msg) { // error handler function
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

int divide(int a, int b) { // function to demonstrate error handling
    if (b == 0) {
        handle_error("Division by zero");
    }
    return a / b;
}

int main(void) {
    int a, b, result;

    printf("Enter two integers to divide:\n");
    scanf("%d %d", &a, &b);

    result = divide(a, b);
    printf("%d / %d = %d\n", a, b, result);

    return 0;
}