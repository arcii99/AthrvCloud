//FormAI DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void divide(int num1, int num2);

int main(void) {
    int num1, num2;

    printf("Enter two numbers.\n");
    scanf("%d %d", &num1, &num2);

    divide(num1, num2);

    return 0;
}

void divide(int num1, int num2) {
    if(num2 == 0) {
        fputs("Error: division by zero.\n", stderr);
        exit(EXIT_FAILURE);
    }

    int result = num1 / num2;
    printf("%d / %d = %d\n", num1, num2, result);

    if(errno == EDOM) {
        fputs("Error: domain error.\n", stderr);
        exit(EXIT_FAILURE);
    }
}