//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
#include <stdio.h>

void printFibonacci(int n) {
    int first = 0, second = 1, next;
    printf("Happy Valentine's Day to my forever Valentine!\n");
    printf("Here is a Fibonacci Sequence that represents our love:\n");
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
}

int main() {
    int n;
    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &n);
    printFibonacci(n);
    return 0;
}