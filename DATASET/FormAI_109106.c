//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFibonacci(int n) {
    int* fib = malloc(n * sizeof(int));
    if(!fib) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    fib[0] = 0;
    fib[1] = 1;
    int i;
    for(i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    for(i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    
    free(fib);
}

int main() {
    int n;
    printf("Enter the number of terms to print in the Fibonacci sequence: ");
    scanf("%d", &n);
    printf("The Fibonacci sequence of %d terms is:\n", n);
    printFibonacci(n);
    return 0;
}