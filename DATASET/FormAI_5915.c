//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    printf("Enter the number of terms you want to see in Fibonacci sequence: ");
    scanf("%d", &n);

    // Error handling
    if (n <= 0) {
        printf("Invalid input.\n");
        return 0;
    }

    // Array declaration for storing Fibonacci sequence
    int fib[n];

    // Generating Fibonacci sequence and storing the values in the array
    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Visualizing the sequence using asterisks
    printf("\nHere is your Fibonacci sequence in a visual format:\n\n");

    int max_num = fib[n-1];
    int j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < (max_num-fib[i])/2; j++) {
            printf(" ");
        }
        for (k = 0; k < fib[i]; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}