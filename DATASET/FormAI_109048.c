//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>

// function to generate fibonacci sequence up to n terms
void fibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Series: %d %d ", first, second);

    for(int i = 2; i < n; i++) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }
}

int main() {
    int n;

    printf("Enter the number of terms for Fibonacci Sequence: ");
    scanf("%d", &n);

    // print fibonacci sequence
    fibonacci(n);

    return 0;
}