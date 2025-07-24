//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>

void fibonacci(int num) {
    int fib[num];

    // Initialize the first two numbers of the sequence
    fib[0] = 0;
    fib[1] = 1;

    // Generate the rest of the sequence
    for (int i = 2; i < num; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Print the sequence
    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < num; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // Create a visualization of the sequence
    printf("Visualization:\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < fib[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int num;

    // Get the number of terms for the sequence
    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &num);

    // Generate the sequence and its visualization
    fibonacci(num);

    return 0;
}