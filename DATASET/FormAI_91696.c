//FormAI DATASET v1.0 Category: Error handling ; Style: bold
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, result;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) { // Check if user entered exactly two integers
        printf("\nError: Invalid input. Please enter two integers.\n");
        exit(1); // Exit the program with error code 1
    }
    if (b == 0) { // Check if denominator is zero
        printf("\nError: Division by zero not allowed.\n");
        exit(2); // Exit the program with error code 2
    }
    result = a / b; // Perform integer division
    if (result < 0) { // Check if result is negative
        printf("\nError: Negative result not allowed.\n");
        exit(3); // Exit the program with error code 3
    }
    printf("\nResult of a/b is %d\n", result); // Print the result
    return 0;
}