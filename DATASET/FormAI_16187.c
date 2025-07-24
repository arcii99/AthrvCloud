//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: real-life
#include <stdio.h>

void displayFibonacci(int n) {
    int i, t1 = 0, t2 = 1, nextTerm;

    printf("Fibonacci sequence: ");

    for (i = 1; i <= n; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    displayFibonacci(n);

    return 0;
}