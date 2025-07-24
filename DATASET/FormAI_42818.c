//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

int main() {
    double x, result;
    printf("Enter a positive value for x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Error: Invalid input.\n");
        return EXIT_FAILURE;
    }
    if (x < 0) {
        printf("Error: x must be positive.\n");
        return EXIT_FAILURE;
    }
    errno = 0;
    result = sqrt(x);
    if (errno == EDOM) {
        printf("Error: sqrt() failed to compute the square root of %g.\n", x);
        return EXIT_FAILURE;
    }
    printf("The square root of %g is %g.\n", x, result);
    return EXIT_SUCCESS;
}