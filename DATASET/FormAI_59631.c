//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: decentralized
#include <stdio.h>

// function to calculate fibonacci sequence
void fibonacci(int n) {
    int first = 0, second = 1;

    // print first 2 numbers
    printf("%d %d ", first, second);

    // print the remaining sequence
    for(int i = 2; i < n; i++) {
        int fib = first + second;
        first = second;
        second = fib;
        printf("%d ", fib);
    }
}

int main() {
    int n;
    printf("Enter the number of terms for fibonacci sequence: ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}