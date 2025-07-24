//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: beginner-friendly
#include <stdio.h>

int fibonacci(int n) {
    if(n == 0 || n == 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n, i, j, k;
    printf("Enter a number for Fibonacci Sequence: ");
    scanf("%d", &n);
    printf("\nFibonacci Sequence up to %d:\n\n", n);

    for(i=0; i<n; i++) {
        for(j=0; j<i; j++) {
            k = fibonacci(j);
            printf("%d ", k);
        }
        printf("\n");
    }

    return 0;
}