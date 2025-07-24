//FormAI DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x = 10;
    int y = 0;
    int result;

    if (y == 0) {
        fprintf(stderr, "Error: Division by zero!");
        exit(EXIT_FAILURE);
    } else {
        result = x / y;
        printf("The result of %d divided by %d is: %d\n", x, y, result);
    }

    return 0;
}