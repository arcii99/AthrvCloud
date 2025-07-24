//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10, y = 0, result;
    // Divide x by y, which results in a divide-by-zero error
    if (y == 0) {
        fprintf(stderr, "Error: Attempted to divide by zero\n");
        exit(EXIT_FAILURE);
    }
    result = x / y; // This line will never be reached due to the exit above
    printf("%d divided by %d is %d\n", x, y, result); // This line will also never be reached
    return 0;
}