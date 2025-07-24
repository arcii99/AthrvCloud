//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Alan Touring
#include <stdio.h>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Print the first two terms of the Fibonacci sequence
    printf("Fibonacci Sequence: %d, %d, ", t1, t2);

    // Generate and print the Fibonacci sequence
    for (int i = 3; i <= n; i++) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        printf("%d, ", nextTerm);
    }

    return 0;
}