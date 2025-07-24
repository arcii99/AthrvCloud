//FormAI DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

// Function to divide two numbers
int divide(int a, int b) {
    if (b == 0) {
        // If denominator is zero, return an error
        errno = EDOM;
        return -1;
    } else {
        return a / b;
    }
}

int main() {
    int dividend, divisor, quotient;

    // Ask user for input
    printf("Enter dividend: ");
    scanf("%d", &dividend);
    printf("Enter divisor: ");
    scanf("%d", &divisor);

    // Call divide function to perform division
    quotient = divide(dividend, divisor);

    // Check if an error occurred during division
    if (quotient == -1) {
        // Print error message based on errno
        if (errno == EDOM) {
            printf("Error: Division by 0\n");
        } else if (errno == ERANGE) {
            printf("Error: Out of Range\n");
        } else {
            printf("Error: Unknown\n");
        }
    } else {
        // If no error occurred, print quotient
        printf("Quotient: %d\n", quotient);
    }

    return 0;
}