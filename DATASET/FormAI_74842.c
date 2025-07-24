//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: beginner-friendly
#include <stdio.h>

void fibonacci(int n) {
    int first = 0, second = 1, next, i;
    printf("%d %d ", first, second);
    for (i = 3; i <= n; i++) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }
}

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("Number of terms should be greater than or equal to 2.");
        return 0;
    }
    fibonacci(n);
    return 0;
}