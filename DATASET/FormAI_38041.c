//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scalable
#include <stdio.h>

// Function to calculate the nth Fibonacci number
int fib(int n) {
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Function to print the Fibonacci sequence
void printFibonacci(int n) {
    int i;
    printf("Fibonacci sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms to be printed: ");
    scanf("%d", &n);
    printFibonacci(n);
    return 0;
}