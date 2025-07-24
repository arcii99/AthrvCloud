//FormAI DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>

// Function to calculate factorial recursively
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate fibonacci sequence recursively
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Main function
int main() {
    // Get user input for factorial
    int fac_input;
    printf("Enter a number to calculate its factorial:\n");
    scanf("%d", &fac_input);

    // Calculate and display factorial
    int fac_output = factorial(fac_input);
    printf("The factorial of %d is %d\n\n", fac_input, fac_output);

    // Get user input for fibonacci sequence
    int fib_input;
    printf("Enter a number to calculate its fibonacci sequence:\n");
    scanf("%d", &fib_input);

    // Calculate and display fibonacci sequence
    printf("The fibonacci sequence of %d numbers is:\n", fib_input);
    for (int i = 0; i < fib_input; i++) {
        printf("%d\n", fibonacci(i));
    }

    return 0;
}