//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n) {
    int a = 0, b = 1, c, i;

    printf("Fibonacci sequence:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", a);

        c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    int n;

    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}