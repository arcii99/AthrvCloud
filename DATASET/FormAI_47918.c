//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, c, i;
    if (n < 1) return;
    printf("%d ", a);
    if (n == 1) return;
    printf("%d ", b);
    for (i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
    }
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    fibonacci(n);
    return 0;
}