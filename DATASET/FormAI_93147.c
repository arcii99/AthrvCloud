//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>

// function to calculate nth Fibonacci number
int fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

// function to print the Fibonacci sequence
void fibonacci_sequence(int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}

int main() {
    int n;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);
    printf("The Fibonacci sequence for the first %d terms is:\n", n);
    fibonacci_sequence(n);
    return 0;
}