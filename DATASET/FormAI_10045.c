//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void divide(int a, int b) {
    if (b == 0) {
        printf("Error: Cannot divide by zero!\n");
        exit(EXIT_FAILURE);
    }
    int result = a / b;
    printf("Result: %d\n", result);
}

int main() {
    int x, y;
    printf("Enter two integers: ");
    if (scanf("%d%d", &x, &y) != 2) {
        printf("Error: Invalid input!\n");
        return EXIT_FAILURE;
    }
    divide(x, y);
    return EXIT_SUCCESS;
}