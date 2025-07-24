//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>

void printSequence(int len) {
    int fibonacciSeq[len];
    
    // Initializing the first two numbers of the sequence
    fibonacciSeq[0] = 0;
    fibonacciSeq[1] = 1;
    
    // Generating the rest of the sequence
    for(int i = 2; i < len; i++) {
        fibonacciSeq[i] = fibonacciSeq[i-1] + fibonacciSeq[i-2];
    }
    
    // Printing out the sequence visually
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < fibonacciSeq[i]; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int length;
    
    printf("Enter the length of the Fibonacci sequence you would like to see: ");
    scanf("%d", &length);
    
    printf("Here is the Fibonacci sequence of length %d: \n", length);
    printSequence(length);
    
    return 0;
}