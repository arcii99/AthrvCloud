//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: recursive
#include <stdio.h>

void fibonacci(int n, int a, int b) {
    if (n <= 0) {
        return;
    }
    printf("%d, ", a);
    fibonacci(n-1, b, a+b);
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci sequence: ");

    fibonacci(n, 0, 1);

    return 0;
}