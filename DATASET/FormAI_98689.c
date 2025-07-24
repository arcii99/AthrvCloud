//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: intelligent
#include <stdio.h>

// function to calculate fibonacci sequence
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

// function to create fibonacci visualization
void fibVisualization(int n) {
    printf("Fibonacci Sequence Visualizer\n\n");
    int i, j;
    for (i = 0; i < n; i++) {
        int num = fib(i);
        for (j = 0; j < num; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of terms to generate: ");
    scanf("%d", &n);
    fibVisualization(n);
    return 0;
}