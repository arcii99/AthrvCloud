//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void visualizeFibonacci(int n) {
    int i, a = 0, b = 1, f = 0;
    printf("%d %d ", a, b);
    for (i = 0; i < n; i++) {
        f = a + b;
        printf("%d ", f);
        a = b;
        b = f;
    }
}

int main() {
    int n;
    printf("Enter the number of terms in Fibonacci sequence to visualize: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Number of terms must be a positive integer.\n");
        exit(1);
    }
    printf("\n\n===================================\n");
    printf("Here is the Fibonacci sequence:\n");
    printf("===================================\n\n");
    visualizeFibonacci(n);
    printf("\n\n===================================\n");
    return 0;
}