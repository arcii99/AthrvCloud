//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

void drawFibonacci(int num) {
    int currentFib;
    int prevFib = 0;
    int tempPrevFib;
    int i;
    printf("0\n");
    for (i = 0; i < num; i++) {
        currentFib = fibonacci(i+1);
        tempPrevFib = prevFib;
        prevFib = currentFib;
        if (currentFib % 2 == 0) {
            printf("\033[1;32m%5d\033[0m", currentFib);
        } else {
            printf("%5d", currentFib);
        }
        if (i % 10 == 0) {
            printf("\n");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please provide the number of terms you wish to see in the Fibonacci sequence.\n");
        return 0;
    }
    int num = atoi(argv[1]);
    if (num < 1) {
        printf("Number of terms must be at least 1.\n");
        return 0;
    }
    drawFibonacci(num);
    return 0;
}