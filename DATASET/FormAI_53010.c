//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: rigorous
#include <stdio.h>

void fibonacciSequence(int n) {
    if (n <= 0) {
        printf("Invalid input: please enter a positive integer.\n");
        return;
    } else if (n == 1) {
        printf("0\n");
        return;
    } else if (n == 2) {
        printf("0 1\n");
        return;
    }

    int fibSeq[n];
    fibSeq[0] = 0;
    fibSeq[1] = 1;

    for (int i = 2; i < n; i++) {
        fibSeq[i] = fibSeq[i-1] + fibSeq[i-2];
    }

    printf("Fibonacci sequence with %d terms: \n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibSeq[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Please enter the number of terms to display in the Fibonacci sequence: ");
    scanf("%d", &n);

    fibonacciSequence(n);

    return 0;
}