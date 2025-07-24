//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: secure
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void print_fibonacci(int n) {
    int i;
    printf("Fibonacci sequence up to %d: ", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input!\n");
        return 1;
    } else if (n < 0) {
        printf("Number must be non-negative!\n");
        return 1;
    }
    print_fibonacci(n);
    return 0;
}