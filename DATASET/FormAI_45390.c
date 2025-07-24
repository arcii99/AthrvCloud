//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: light-weight
#include <stdio.h>

void drawIteration(int n, int x, int y, int width);

int main() {
    int n;
    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    int width = n * 6;
    int height = n * 2.5;
    printf("The Fibonacci sequence up to %d is:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
        drawIteration(fib[i], i*6, i*2.5, width);
    }

    return 0;
}

void drawIteration(int n, int x, int y, int width) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");

    if (n == 1) {
        printf("*\n");
    }
    else {
        drawIteration(n-1, x, y+2, width);
        drawIteration(n-2, x, y+2, width-n*6/10);
    }

    for (int i = 0; i < width - (n+1); i++) {
        printf(" ");
    }

    printf("<%d,%d,%.0lf>", x, y, n);
}