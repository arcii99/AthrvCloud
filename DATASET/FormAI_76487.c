//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>

void printFibonacci(int n);

int main() {
    int n;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);
    printFibonacci(n);
    return 0;
}

void printFibonacci(int n) {
    int firstTerm = 0, secondTerm = 1, nextTerm;

    printf("Fibonacci Sequence:\n");

    for (int i = 1; i <= n; ++i) {
        printf("%d\n", firstTerm);
        nextTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }
}