//FormAI DATASET v1.0 Category: Error handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

void error(char *msg, int code) {
    printf("ERROR: %s\n", msg);
    exit(code);
}

int main() {
    int a, b, res;
    printf("Enter two integers: ");
    if (scanf("%d%d", &a, &b) != 2) {
        error("Invalid input, please enter two integers.", 1);
    }
    if (b == 0) {
        error("Division by zero not allowed.", 2);
    }
    res = a / b;
    printf("%d divided by %d is %d\n", a, b, res);
    return 0;
}