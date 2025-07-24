//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complete
#include <stdio.h>

int fibonacci(int n);

int main() {
    int n, i, result;
    
    printf("Welcome to the Fibonacci sequence visualizer!\n");
    printf("How many numbers of the Fibonacci sequence would you like to visualize?\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        result = fibonacci(i);
        printf("%d ", result);
    }
    
    printf("\n");
    return 0;
}

int fibonacci(int n) {
    if(n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}