//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int terms);

int main() {
    int numTerms;
    printf("Enter the number of terms you want to generate: ");
    scanf("%d", &numTerms);
    printFibonacci(numTerms);
    return 0;
}

void printFibonacci(int terms) {
    int i, currentTerm = 0, nextTerm = 1, temp;
    printf("\nThe Fibonacci Sequence of %d terms:\n", terms);
    for (i = 1; i <= terms; i++) {
        printf("%d ", currentTerm);
        temp = currentTerm + nextTerm;
        currentTerm = nextTerm;
        nextTerm = temp;
    }
    printf("\n");
}