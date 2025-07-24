//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
#include <stdio.h>

// A function that computes the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// A function that prints out a cheerful message
void printCheerfulMessage() {
    printf("Hooray! Your program is running smoothly!\n");
}

int main() {
    int n = 10; // Calculate the factorial of 10
    int fact = factorial(n);

    // Print out the result and a cheerful message
    printf("The factorial of %d is %d.\n", n, fact);
    printCheerfulMessage();

    return 0;
}