//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: beginner-friendly
#include <stdio.h>

int get_fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return get_fibonacci(n - 1) + get_fibonacci(n - 2);
}

void visualizer(int n) {
    for (int i = 0; i < n; i++) {
        int term = get_fibonacci(i);
        for (int j = 0; j < term; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("How many terms of the Fibonacci sequence would you like to visualize? ");
    scanf("%d", &n);
    visualizer(n);
    return 0;
}