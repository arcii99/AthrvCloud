//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: inquisitive
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

void drawLine(int length) {
    for (int i = 0; i < length; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    int numberOfTerms;
    printf("How many terms of Fibonacci sequence you want to visualize? ");
    scanf("%d", &numberOfTerms);

    int fibonacciSequence[numberOfTerms];

    // Calculate Fibonacci sequence
    for (int i = 0; i < numberOfTerms; i++) {
        fibonacciSequence[i] = fibonacci(i);
    }

    // Find the largest number in the sequence
    int largestNumber = fibonacciSequence[0];
    for (int i = 1; i < numberOfTerms; i++) {
        if (fibonacciSequence[i] > largestNumber) {
            largestNumber = fibonacciSequence[i];
        }
    }

    // Visualize the sequence
    for (int i = numberOfTerms - 1; i >= 0; i--) {
        int currentNumber = fibonacciSequence[i];
        int numberOfStars = (currentNumber * 50) / largestNumber;
        drawLine(numberOfStars);
    }

    return 0;
}