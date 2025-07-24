//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: calm
#include <stdio.h>

void printFibonacci(int n);

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Prints Fibonacci sequence
    printFibonacci(n);

    return 0;
}

void printFibonacci(int n) {
    int a = 0, b = 1, c;

    // Special case for the first two terms
    if (n < 1) {
        return;
    } else if (n == 1) {
        printf("%d", a);
    } else if (n == 2) {
        printf("%d %d", a, b);
    } else {
        printf("%d %d ", a, b);
        for (int i = 3; i <= n; i++) {
            c = a + b;
            printf("%d ", c);
            a = b;
            b = c;
        }
    }
}