//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: rigorous
#include <stdio.h>

// Recursive function to calculate fibonacci sequence
int fibonacci(int n);

int main() {
    int n;

    // Prompt user for input
    printf("Enter the number of terms to generate in fibonacci sequence: ");
    scanf("%d", &n);

    // Print the fibonacci sequence
    for(int i=0; i<n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}

int fibonacci(int n) {
    // Base cases
    if(n == 0) {
        return 0;
    }
    else if(n == 1) {
        return 1;
    }
    // Recursive case
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}