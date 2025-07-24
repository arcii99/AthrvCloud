//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complex
#include <stdio.h>

// Function to generate the Fibonacci sequence visually
void fibonacciSequenceVisualizer(int n) {
    int a = 0, b = 1, c, i, j;
    for (i = 0; i < n; i++) {
        // Display the row number
        printf("%02d: ", i + 1);
        for (j = 0; j <= i; j++) {
            // Calculate the next number in the sequence
            if (j == 0) {
                c = a;
            } else if (j == 1) {
                c = b;
            } else {
                c = a + b;
                a = b;
                b = c;
            }
            // Display the number visually
            if (c % 2 == 0) {
                printf("* ");
            } else {
                printf("+ ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows to generate: ");
    scanf("%d", &n);
    fibonacciSequenceVisualizer(n);
    return 0;
}