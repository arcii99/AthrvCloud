//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// A function to generate the nth Fibonacci number
int fibonacci(int n) {
    int a = 0, b = 1, i, temp;
    if (n == 0)
        return a;
    for (i = 2; i < n+1; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// Function to print the Fibonacci numbers
void fiboSeqVisualizer(int n) {
    int i, j, k, space = n-1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < space; j++)
            printf("    "); // 4 spaces
        space--;
        int count = i+1;
        for (k = 0; k <= i; k++) {
            printf("%4d", fibonacci(count));
            count--;
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    fiboSeqVisualizer(n);
    return 0;
}