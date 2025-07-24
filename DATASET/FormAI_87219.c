//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the fibonacci sequence up to n elements
int* fib(int n) {
    int* fib_seq = (int*) malloc(n * sizeof(int)); // Dynamically allocate memory for the sequence
    fib_seq[0] = 0; // First element
    fib_seq[1] = 1; // Second element

    for (int i = 2; i < n; i++) {
        fib_seq[i] = fib_seq[i-1] + fib_seq[i-2]; // Calculate the next element by adding the previous two elements
    }

    return fib_seq; // Return the fibonacci sequence array
}

// Function to print the fibonacci sequence in a visual format
void print_fib(int* fib_seq, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", fib_seq[i]); // Print the number

        // Print a bar for every 10th number
        if (i % 10 == 9) {
            printf("|");
        }

        // Move to the next line every 20th number
        if (i % 20 == 19) {
            printf("\n");
        }
    }
    printf("\n"); // Move to a new line
}

int main() {
    int n = 100; // Number of fibonacci sequence elements to calculate
    int* fib_seq = fib(n); // Calculate the fibonacci sequence

    // Print the fibonacci sequence in a visual format
    printf("Fibonacci Sequence (%d Elements):\n", n);
    print_fib(fib_seq, n);

    free(fib_seq); // Free the dynamically allocated memory

    return 0;
}