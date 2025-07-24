//FormAI DATASET v1.0 Category: Error handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void error(char *msg, int exit_code) {
    printf("ERROR: %s\n", msg);
    exit(exit_code);
}

int main() {
    int num1, num2;
    float quotient;

    printf("Enter an integer: ");
    if (scanf("%d", &num1) != 1) {
        error("Invalid input for first number.", 1);
    }

    printf("Enter another integer: ");
    if (scanf("%d", &num2) != 1) {
        error("Invalid input for second number.", 1);
    }

    if (num2 == 0) {
        error("Divide-by-zero error.", 1);
    }

    quotient = (float) num1 / num2;

    printf("%d divided by %d is %.2f\n", num1, num2, quotient);

    return 0;
}