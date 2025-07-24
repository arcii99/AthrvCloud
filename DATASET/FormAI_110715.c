//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define ERROR(msg) \
do { perror(msg); exit(EXIT_FAILURE); } while (0)

int divide(int a, int b) {
    if(b == 0) {
        ERROR("Cannot divide by zero");
    }
    return a / b;
}

int main() {
    int a, b, result;

    // Getting input from the user
    printf("Enter the first number: ");
    if(scanf("%d", &a) != 1) {
        ERROR("Failed to read input");
    }

    printf("Enter the second number: ");
    if(scanf("%d", &b) != 1) {
        ERROR("Failed to read input");
    }

    // handling error while dividing
    result = divide(a, b);

    // printing the result
    printf("%d / %d = %d\n", a, b, result);

    return 0;
}