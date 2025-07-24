//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: careful
#include <stdio.h>

// Function to print the Fibonacci sequence up to n terms
void printFibonacciSequence(int n) {
    int a = 0, b = 1, c, i;
    printf("%d %d ", a, b); // print the first two terms of the sequence

    for (i = 3; i <= n; i++) { // loop through the remaining terms
        c = a + b; // calculate the next term in the sequence
        printf("%d ", c); // print the current term
        a = b; // move b to a
        b = c; // move c to b
    }
}

int main() {
    int n;
    printf("Enter the number of terms to print: ");
    scanf("%d", &n);

    // Validate user input
    if (n < 1) {
        printf("Error: number of terms must be at least 1.\n");
        return 1;
    }

    printf("\nFibonacci sequence up to %d terms:\n", n);
    printFibonacciSequence(n);
    printf("\n");

    return 0;
}