//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complete
#include <stdio.h>

int fibonacci(int n);

int main() {
    int n, i;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);
    printf("\nFibonacci Sequence:\n");
    
    for(i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    
    return 0;
}

int fibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}