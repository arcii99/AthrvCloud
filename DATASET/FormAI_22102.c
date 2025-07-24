//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next;

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Print the first two terms of the sequence
    printf("Fibonacci Sequence: %d, %d, ", first, second);

    // Compute and print the rest of the sequence
    for (int i = 2; i < n; i++) {
        next = first + second;
        printf("%d, ", next);
        first = second;
        second = next;
    }

    printf("\n");

    return 0;
}