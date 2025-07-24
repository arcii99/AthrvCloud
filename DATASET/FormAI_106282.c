//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: recursive
#include <stdio.h>

int recursive_fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
    }
}

void display_fibonacci_sequence(int n) {
    int i;
    printf("Fibonacci Sequence: ");
    for (i = 0; i < n; i++) {
        printf("%d ", recursive_fibonacci(i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);
    display_fibonacci_sequence(n);
    return 0;
}