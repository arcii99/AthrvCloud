//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: decentralized
#include <stdio.h>

// function to calculate Fibonacci sequence
int fib(int n);

int main() {
    int n; // user input
    printf("Enter the number of terms you want to generate in the Fibonacci sequence: ");
    scanf("%d", &n);
    
    // print the sequence
    printf("\nFibonacci sequence of %d terms:\n", n);
    for(int i=0; i<n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
    return 0;
}

// recursive function to calculate the nth term of Fibonacci sequence
int fib(int n) {
    if(n == 0 || n == 1) {
        return n;
    } else {
        return fib(n-1) + fib(n-2);
    }
}