//FormAI DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void cleanup() {
    // perform cleanup tasks
    printf("Performing cleanup tasks...\n");
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter two numbers.\n");
        exit(1);
    }
    if (num2 == 0) {
        printf("Division by zero is not allowed.\n");
        exit(1);
    }
    int res = num1 / num2;
    printf("%d divided by %d is %d\n", num1, num2, res);

    // register the cleanup function to run in case of errors
    atexit(cleanup);
    return 0;
}