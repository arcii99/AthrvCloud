//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>

// Function to print Fibonacci sequence up to requested limit
void fibonacci(int limit) {
    int first = 0, second = 1, next;

    printf("Fibonacci sequence up to %d: ", limit);

    // Print first two terms of the sequence
    printf("%d %d ", first, second);

    // Calculate and print the remaining terms of the sequence
    next = first + second;
    while (next <= limit) {
        printf("%d ", next);
        first = second;
        second = next;
        next = first + second;
    }
    printf("\n");
}

int main() {
    int limit;

    printf("Enter the limit for the Fibonacci sequence: ");
    scanf("%d", &limit);

    fibonacci(limit);

    return 0;
}