//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int dividend = 5, divisor = 0;

    printf("Mathematical Division: %d / %d = ", dividend, divisor);

    if (divisor == 0) {
        fprintf(stderr, "Divide by Zero Error\n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("%d\n", dividend/divisor);
    }
    return 0;
}