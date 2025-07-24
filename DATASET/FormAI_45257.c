//FormAI DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void error_handling(char *msg);

int main(int argc, char *argv[]) {
    int num1, num2, quotient;

    if (argc != 3) {
        error_handling("Invalid number of arguments.");
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);

    if (num2 == 0) {
        error_handling("Division by zero not allowed.");
    }

    quotient = num1 / num2;

    printf("%d divided by %d is %d\n", num1, num2, quotient);

    return 0;
}

void error_handling(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}