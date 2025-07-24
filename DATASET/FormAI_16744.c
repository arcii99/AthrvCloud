//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: visionary
#include <stdio.h>

// Function to calculate the fibonacci sequence and print it in a visual format
void fibonacci_visualizer(int n) {
    int sequence[n];

    sequence[0] = 0;
    sequence[1] = 1;

    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }

    // Print the sequence in a visual format
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sequence[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of terms in the fibonacci sequence: ");
    scanf("%d", &n);

    fibonacci_visualizer(n);

    return 0;
}