//FormAI DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

// Define a function to calculate the square root of a number
double sqrt_error_handle(double num) {
    if (num < 0) {
        errno = EDOM; // Set error code to invalid argument error
        return nan(""); // Return NaN (not a number) to signal error
    } else {
        return sqrt(num); // Calculate square root of number
    }
}

int main() {
    double num, result;
    printf("Enter a number to calculate its square root: ");
    if (scanf("%lf", &num) == 1) { // Check if input is valid
        result = sqrt_error_handle(num); // Call error handling function to calculate square root
        if (errno == EDOM) { // Check if error occurred during calculation
            printf("Error: Invalid argument.\n"); // Print error message
        } else {
            printf("The square root of %.2lf is %.2lf.\n", num, result); // Print result
        }
    } else {
        printf("Error: Invalid input.\n"); // Print error message if input is invalid
    }
    return 0;
}