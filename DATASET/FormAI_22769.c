//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int a, b;
    printf("Enter two numbers to divide: ");
    scanf("%d %d", &a, &b);

    if (b == 0) {
        fprintf(stderr, "Division by zero is not allowed!\n");
        exit(EXIT_FAILURE);
    }

    int result = a/b;
    printf("Result is: %d\n", result);

    return 0;
}