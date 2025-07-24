//FormAI DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int dividend, divisor, result;

    if (argc != 3) {
        printf("Usage: %s <dividend> <divisor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert arguments from strings to integers
    dividend = atoi(argv[1]);
    divisor = atoi(argv[2]);

    // Catch divide by zero error
    if (divisor == 0) {
        printf("ERROR: Cannot divide by zero\n");
        return EXIT_FAILURE;
    }

    // Perform division operation
    result = dividend / divisor;

    // Check for overflow error
    if (errno == ERANGE) {
        printf("ERROR: Overflow detected\n");
        return EXIT_FAILURE;
    }

    // Print result
    printf("%d / %d = %d\n", dividend, divisor, result);

    return EXIT_SUCCESS;
}