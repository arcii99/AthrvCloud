//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>


// This function uses recursion to calculate the nth Fibonacci number
int fibonacci(int n) {
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}


// This function prints out the Fibonacci sequence up to the nth number
void visualizeFibonacciSequence(int n) {
    if(n <= 0) {
        printf("Invalid input. n must be a positive integer.\n");
        return;
    }
    
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}


int main() {
    int n = -1;
    
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    
    while(n < 0) {
        printf("Please enter the number of Fibonacci numbers you would like to see: ");
        scanf("%d", &n);
        if(n < 0)
            printf("Invalid input. n must be a positive integer.\n");
    }
    
    visualizeFibonacciSequence(n);

    return 0;
}