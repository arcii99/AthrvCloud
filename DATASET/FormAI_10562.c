//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: recursive
#include <stdio.h>

void printFibonacci(int num, int prev, int current, int count);

int main() {
    int count;

    printf("Enter the number of terms in Fibonacci Series: ");
    scanf("%d", &count);

    // Print the first two terms of the series
    printf("Fibonacci Series: %d %d ", 0, 1);

    // Pass 2 as count because the first two terms have already been printed
    printFibonacci(count - 2, 0, 1, 0);

    return 0;
}

void printFibonacci(int num, int prev, int current, int count) {
    // Base case
    if (count == num) {
        return;
    }

    int next = prev + current;

    // Print the next term
    printf("%d ", next);

    // Recursive call to print the next term
    printFibonacci(num, current, next, count + 1);
}