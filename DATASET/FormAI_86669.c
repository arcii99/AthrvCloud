//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if(n <= 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void printFibonacciSequence(int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}

void drawFibonacciBars(int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < fibonacci(i); j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter number of terms in Fibonacci sequence: ");
    scanf("%d", &n);

    printf("Fibonacci sequence:\n");
    printFibonacciSequence(n);

    printf("\n\nFibonacci bars:\n");
    drawFibonacciBars(n);

    return 0;
}