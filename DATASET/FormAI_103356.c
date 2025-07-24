//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: beginner-friendly
#include <stdio.h>

void fibonacciSequenceVisualizer(int n) {
    int a = 0, b = 1, c, i;

    printf("\nHere's the Fibonacci sequence up to %d:\n\n", n);

    for (i = 1; i <= n; ++i) {
        if (i == 1) {
            printf("%d\t", a);
            continue;
        }

        if (i == 2) {
            printf("%d\t", b);
            continue;
        }

        c = a + b;
        a = b;
        b = c;

        printf("%d\t", c);

        if (i % 10 == 0) // adds a new line every ten numbers
            printf("\n");
    }
}

int main() {
    int n;

    printf("Please enter the number of Fibonacci sequence terms you would like to visualize: ");
    scanf("%d", &n);

    fibonacciSequenceVisualizer(n);

    return 0;
}