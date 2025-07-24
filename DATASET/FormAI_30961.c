//FormAI DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handleError(char* message) {
    fprintf(stderr, "Error: %s\n", message);
}

int divide(int x, int y) {
    if (y == 0) {
        handleError("Division by zero!");
        exit(EXIT_FAILURE);
    }
    return x / y;
}

int main() {
    int x, y, result;
    char buffer[256];

    printf("Enter the value of x: ");
    fgets(buffer, sizeof(buffer), stdin);
    x = atoi(buffer);

    printf("Enter the value of y: ");
    fgets(buffer, sizeof(buffer), stdin);
    y = atoi(buffer);

    result = divide(x, y);

    printf("%d / %d = %d\n", x, y, result);
    return 0;
}