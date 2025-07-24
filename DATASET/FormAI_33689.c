//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>

void fibonacciSequence(int n);

int main() {
    int n;
    printf("Enter the number of terms to generate in Fibonacci sequence: ");
    scanf("%d", &n);
    fibonacciSequence(n);
    return 0;
}

void fibonacciSequence(int n) {
    int first = 0, second = 1, next;
    printf("The Fibonacci sequence for the first %d terms is:\n", n);
    for(int i = 0; i < n; i++) {
        if(i <= 1) {
            next = i;
        }
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d, ", next);
    }
    printf("\n");
}