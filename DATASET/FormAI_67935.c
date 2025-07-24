//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>

void printFibonacci(int n) {
    int a = 0;
    int b = 1;
    int c = a + b;
    int i;
    
    // Print the initial values
    printf("%d ", a);
    printf("%d ", b);

    // Generate the Fibonacci sequence up to the given limit
    for (i = 2; i < n; i++) {
        printf("%d ", c);
        a = b;
        b = c;
        c = a + b;
    }
    printf("\n");
}

void printFibonacciArt(int n) {
    int a = 0;
    int b = 1;
    int c = a + b;
    int i, j;
    char e = ' ', s = '*';

    // Generate the ASCII art based on the Fibonacci sequence
    for (i = 2; i < n; i++) {
        for (j = 0; j < c; j++) {
            if (j == a || j == b) {
                printf("%c", s);
            } else {
                printf("%c", e);
            }
        }
        printf("\n");
        a = b;
        b = c;
        c = a + b;
    }
}

int main() {
    int n = 10;

    printf("First %d Fibonacci numbers: ", n);
    printFibonacci(n);

    printf("\nASCII Art Fibonacci Sequence: \n");
    printFibonacciArt(n);

    return 0;
}