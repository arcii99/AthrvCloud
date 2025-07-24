//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: intelligent
#include <stdio.h>

// function to calculate and print the Fibonacci sequence up to a given number of terms
void printFibonacci(int n) {
    int fibo1 = 0, fibo2 = 1, i, fibonacci;
    printf("%d %d ", fibo1, fibo2); // print the first two terms
    for (i = 2; i < n; i++) {
        fibonacci = fibo1 + fibo2;
        printf("%d ", fibonacci);
        fibo1 = fibo2;
        fibo2 = fibonacci;
    }
}

// function to draw a square with a given side length
void drawSquare(int side) {
    int i, j;
    for (i = 0; i < side; i++) {
        for (j = 0; j < side; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

// main function to call both functions and create a Fibonacci sequence visualizer
int main() {
    int numTerms;
    printf("How many terms of the Fibonacci sequence would you like to see? ");
    scanf("%d", &numTerms);
    printf("\nHere are the first %d terms of the Fibonacci sequence: ", numTerms);
    printFibonacci(numTerms);

    int length = numTerms * 2 - 1;
    printf("\n\nHere is a square with side length equal to the %dth term of the Fibonacci sequence: \n", numTerms);
    drawSquare(length);

    return 0;
}