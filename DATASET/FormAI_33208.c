//FormAI DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>

int main() {

    int num1, num2;

    printf("Enter two numbers to divide: ");

    if (scanf("%d%d", &num1, &num2) != 2) {
        fprintf(stderr, "Error: invalid input\n");
        exit(EXIT_FAILURE);
    }

    if (num2 == 0) {
        fprintf(stderr, "Error: cannot divide by zero\n");
        exit(EXIT_FAILURE);
    }

    int result = num1 / num2;

    printf("%d / %d = %d\n", num1, num2, result);

    return 0;
}