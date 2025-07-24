//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include <stdio.h>

void fibonacci(int n) {
    int first = 0, second = 1;
    printf("%d %d ", first, second);
    for (int i = 2; i < n; i++) {
        int next = first + second;
        first = second;
        second = next;
        printf("%d ", next);
    }
}

void printStars(int n) {
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");
}

void drawFibonacci(int n) {
    int first = 0, second = 1;
    for (int i = 0; i < n; i++) {
        int next = first + second;
        first = second;
        second = next;
        printStars(next);
    }
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci sequence:\n");
    fibonacci(n);
    printf("\n\nFibonacci visualizer:\n");
    drawFibonacci(n);
    return 0;
}