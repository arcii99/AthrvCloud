//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: modular
#include <stdio.h>

int fibonacci(int);
void printFibonacci(int);

int main() {
    int n;

    printf("Enter the number of terms to display in the Fibonacci Sequence: ");
    scanf("%d", &n);

    printf("Fibonacci sequence for %d terms:\n", n);
    printFibonacci(n);

    return 0;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void printFibonacci(int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}