//FormAI DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 5;
    int y = 0;
    int result;

    if (y == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        exit(EXIT_FAILURE);
    } else {
        result = x / y;
        printf("Result: %d\n", result);
    }

    return 0;
}