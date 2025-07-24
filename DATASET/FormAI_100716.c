//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 15

// Function declarations
void generateFibonacciSequence(int num, int *fibonacciSeq);
void printFibonacciSequence(int num, int *fibonacciSeq);
void drawFibonacciSequence(int num, int *fibonacciSeq);

// Main function
int main() {
    int fibonacciSeq[MAX_NUM];
    generateFibonacciSequence(MAX_NUM, fibonacciSeq);
    printf("The first %d numbers in the Fibonacci sequence are:\n", MAX_NUM);
    printFibonacciSequence(MAX_NUM, fibonacciSeq);
    drawFibonacciSequence(MAX_NUM, fibonacciSeq);
    return 0;
}

// Function to generate the Fibonacci sequence
void generateFibonacciSequence(int num, int *fibonacciSeq) {
    int i;
    fibonacciSeq[0] = 0;
    fibonacciSeq[1] = 1;
    for (i = 2; i < num; i++) {
        fibonacciSeq[i] = fibonacciSeq[i-1] + fibonacciSeq[i-2];
    }
}

// Function to print the Fibonacci sequence
void printFibonacciSequence(int num, int *fibonacciSeq) {
    int i;
    for (i = 0; i < num; i++) {
        printf("%d ", fibonacciSeq[i]);
    }
    printf("\n");
}

// Function to draw the Fibonacci sequence
void drawFibonacciSequence(int num, int *fibonacciSeq) {
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < fibonacciSeq[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}