//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: careful
#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Check for valid input
    if(n < 1) {
        printf("Invalid input. Number of terms must be greater than or equal to 1.");
        return 0;
    }

    // First two terms of the Fibonacci sequence
    int a = 0, b = 1;

    // Printing the first two terms
    printf("%d %d ", a, b);

    // Output the next terms of the sequence
    for(int i = 3; i <= n; i++) {
        int c = a + b;
        printf("%d ", c);

        // Update the previous two terms
        a = b;
        b = c;
    }

    return 0;
}