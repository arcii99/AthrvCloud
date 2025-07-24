//FormAI DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int divide(int x, int y) {
    if (y == 0) {
        // Throw an error message if division by zero is attempted
        fprintf(stderr, "Error: Division by zero\n");
        exit(EXIT_FAILURE);
    }
    return x / y;
}

int main() {
    int a, b, result;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Error handling block
    if (b == 0) {
        fprintf(stderr, "Error: Cannot divide by zero\n");
        return EXIT_FAILURE;
    } else {
        result = divide(a, b);
        printf("Result: %d\n", result);
        return EXIT_SUCCESS;
    }
}