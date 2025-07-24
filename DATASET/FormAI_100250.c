//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: irregular
#include <stdio.h>

// Function prototypes
void printFibonacci(int n);

int main() {
    int n;

    // Get input from user
    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &n);

    // Print the sequence
    printFibonacci(n);

    return 0;
}

// Function to print the Fibonacci sequence
void printFibonacci(int n) {
    int a = 0, b = 1, c, i;

    // Print the first two terms of the sequence
    printf("%d %d ", a, b);

    // Print the rest of the terms in the sequence
    for(i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;

        // Print the term with some visual flair
        if(c % 3 == 0 && c % 5 == 0) {
            printf("*%d* ", c);
        }
        else if(c % 3 == 0) {
            printf("+%d+ ", c);
        }
        else if(c % 5 == 0) {
            printf("#%d# ", c);
        }
        else {
            printf("%d ", c);
        }
    }
}