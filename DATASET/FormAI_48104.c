//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: realistic
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

void printFibonacci(int n) {
    printf("\nC Fibonacci Sequence Visualizer\n");
    printf("-------------------------------\n");
    printf("Fibonacci sequence up to %d:\n", n);
    
    for (int i = 0; i < n; i++) {
        int fib = fibonacci(i);
        printf("%d ", fib);
        for (int j = 0; j < fib; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of terms to display: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid input!");
        return 0;
    }
    
    printFibonacci(n);
    
    return 0;
}