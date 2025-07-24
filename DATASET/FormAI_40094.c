//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include <stdio.h>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;

    // Ask user for the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Check if the input is valid
    if (n <= 0) {
        printf("Invalid input!\n");
        return 0;
    }

    // Print the first two terms of the sequence
    printf("Fibonacci Sequence: %d, %d, ", t1, t2);

    // Calculate and print the next terms of the sequence
    nextTerm = t1 + t2;

    while (nextTerm <= n) {
        printf("%d, ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }

    printf("\n");
    return 0;
}