//FormAI DATASET v1.0 Category: Recursive ; Style: rigorous
#include <stdio.h>

// Function declaration
int fib(int n);

int main() {
    int num;
    printf("Enter a number to find its fibonacci series: ");
    scanf("%d", &num);
    printf("Fibonacci series for %d is: ", num);

    // Printing Fibonacci series
    for(int i = 0; i < num; i++) {
        printf("%d ", fib(i));
    }

    return 0;
}

// Function to calculate Fibonacci series using recursion
int fib(int n) {
    if(n == 0) {
        return 0;
    }
    else if(n == 1) {
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}