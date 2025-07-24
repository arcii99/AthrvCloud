//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: modular
#include<stdio.h>
#include<stdlib.h>

int getN() {
    int n;
    printf("Enter the number of terms to print: ");
    scanf("%d", &n);
    return n;
}

void printFibonacci(int n) {
    int a = 0, b = 1, c;
    printf("%d %d",a, b);
    for (int i = 2; i < n; i++) {
        c = a + b;
        printf(" %d", c);
        a = b;
        b = c;
    }
    printf("\n");
}

int main() {
    int n = getN();
    printFibonacci(n);
    return 0;
}