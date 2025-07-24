//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n) {
    int sequence[n];
    sequence[0] = 0;
    sequence[1] = 1;

    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }

    // Print the sequence
    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sequence[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n = 10; // Change this value to change the length of the sequence
    fibonacci(n);
    return 0;
}