//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Function to calculate fibonacci sequence and return the nth number in the sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Function to draw the fibonacci sequence visually
void drawFibonacci(int n) {
    int i, j, k, q, a, b;
    for (i = 0; i < n; i++) {
        a = fibonacci(i);
        b = fibonacci(i+1);
        printf("%d:\t", a);
        for (j = 0; j < a; j++) {
            for (k = 0; k < j; k++) {
                printf("# ");
            }
            printf("\n");
        }
        
        for (q = 0; q < b; q++) {
            printf("| ");
        }
        printf("\n\n");
    }
}

// Main function
int main() {
    int n = 10;  // Change this to change how many numbers in the sequence to display
    drawFibonacci(n);
    return 0;
}