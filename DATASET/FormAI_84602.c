//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

void fibonacciSequence(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci Sequence:\n");

    for (int i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = a + b;
            a = b;
            b = next;
        }
        // Visualization: the bar graph represents the current number in the sequence
        for (int j = 0; j < next; j++) {
            printf("|");
        }
        printf(" %d\n", next);
    }
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.");
        exit(0);
    }

    fibonacciSequence(n);
    return 0;
}