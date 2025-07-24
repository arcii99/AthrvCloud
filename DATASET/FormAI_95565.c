//FormAI DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divide(int dividend, int divisor) {
    if (divisor == 0) {
        fprintf(stderr, "Error: division by zero\n");
        exit(EXIT_FAILURE);
    }
    return dividend / divisor;
}

int main() {
    int a, b, c;
    char input[10];

    printf("Welcome to the Division Calculator!\n");
    printf("Please enter two integers to divide: ");

    fgets(input, 10, stdin);
    a = atoi(input);

    fgets(input, 10, stdin);
    b = atoi(input);

    c = divide(a, b);

    printf("%d divided by %d is %d\n", a, b, c);

    printf("Thank you for using the Division Calculator!\n");

    return 0;
}