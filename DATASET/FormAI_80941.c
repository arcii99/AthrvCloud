//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, result;

    // Prompt the user to enter two integer values
    printf("Enter two integer values:\n");

    // Read the integer values from the standard input
    if(scanf("%d %d", &a, &b) != 2) {
        fprintf(stderr, "Failed to read both integer values\n");

        // Terminate the program with a non-zero error code
        exit(EXIT_FAILURE);
    }

    // Check for a possible division by zero
    if(b == 0) {
        fprintf(stderr, "Division by zero is not allowed\n");

        // Exit the program with a non-zero error code
        exit(EXIT_FAILURE);
    }

    // Perform the integer division and store the result
    result = a / b;

    // Print the result to the standard output
    printf("%d divided by %d is equal to %d\n",a, b, result);

    // Exit the program normally
    exit(EXIT_SUCCESS);
}