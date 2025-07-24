//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Function to print the Fibonacci sequence up to n terms
void fibonacciSequence(int n) {
    int i, t1 = 0, t2 = 1, nextTerm;

    // Print the first two terms
    printf("Fibonacci Sequence: %d, %d, ", t1, t2);

    // Calculate next terms using previous terms t1 and t2
    for (i = 3; i <= n; i++) {
        nextTerm = t1 + t2;     // Add the previous two terms to get the next term
        printf("%d, ", nextTerm);
        t1 = t2;                // Assign the value of the second term to the first term
        t2 = nextTerm;          // Assign the value of the next term to the second term
    }
}

int main(void) {
    int n;

    printf("Enter the number of terms you want in the Fibonacci Sequence: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer.");
        return 0;
    }

    fibonacciSequence(n);

    return 0;
}