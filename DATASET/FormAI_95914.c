//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void printFibonacci(int);

int main() {
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");

    printf("Enter the number of terms you want to print: ");
    int n;
    scanf("%d", &n);

    printf("Generating Fibonacci Sequence... Please wait...\n\n");
    printFibonacci(n);

    return 0;
}

// function to print fibonacci sequence and visualizer
void printFibonacci(int n) {
    int a = 0, b = 1, c;
    printf("%d %d ", a, b);

    // print the fibonacci sequence
    for (int i = 2; i < n; i++) {
        c = a + b;
        printf("%d ", c);

        // print visualizer
        int random = rand() % 10 + 1;
        if (random <= 4) {
            printf("*");
        } else if (random <= 7) {
            printf("-");
        } else {
            printf("|");
        }

        a = b;
        b = c;
    }
}