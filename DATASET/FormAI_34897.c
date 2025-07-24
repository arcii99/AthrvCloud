//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Donald Knuth
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(int argc, char *argv[]) {
    int n;
    printf("Enter the number of terms you want in Fibonacci Sequence: ");
    scanf("%d", &n);
    printf("\nFibonacci Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}