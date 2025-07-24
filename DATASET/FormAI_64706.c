//FormAI DATASET v1.0 Category: Recursive ; Style: Alan Touring
#include <stdio.h>

// Define a recursive function to compute factorials
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int input;

    // Ask the user for an integer input
    printf("Please enter an integer: ");
    scanf("%d", &input);

    // Compute the factorial using the recursive function
    int result = factorial(input);

    // Print the result to the console
    printf("The factorial of %d is %d.\n", input, result);

    return 0;
}