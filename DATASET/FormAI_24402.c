//FormAI DATASET v1.0 Category: Error handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void error(char *message) {
    fprintf(stderr, "Error: %s", message);
    exit(1);
}

int divide(int a, int b) {
    if (b == 0) {
        error("Division by zero!");
    }
    return a / b;
}

int main() {
    int a, b, result;

    printf("Enter two numbers to divide: ");
    if (scanf("%d %d", &a, &b) != 2) {
        error("Invalid input!");
    }

    result = divide(a, b);
    printf("The result is: %d\n", result);

    return 0;
}