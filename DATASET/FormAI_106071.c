//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: detailed
#include <stdio.h>

void fibonacciVisualizer(int n) {
    int a = 0, b = 1, c = a + b;
    printf("%d %d ", a, b);

    for (int i = 0; i < n-2; i++) {
        a = b;
        b = c;
        c = a + b;

        // print the sequence visually
        printf("%d ", c);
        for (int j = 0; j < c-1; j++) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("How many terms of Fibonacci sequence would you like to visualize?\n");
    scanf("%d", &n);

    fibonacciVisualizer(n);

    return 0;
}