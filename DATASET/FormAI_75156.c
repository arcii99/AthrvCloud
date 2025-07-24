//FormAI DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;

    printf("Please enter two numbers to divide.\n");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Input error: please enter two valid numbers.\n");
        exit(1);
    }

    if (num2 == 0) {
        printf("Division by zero error: cannot divide by zero.\n");
        exit(1);
    }

    result = num1 / num2;
    printf("%d divided by %d is equal to %d.\n", num1, num2, result);

    return 0;
}