//FormAI DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>

int main() {
    printf("Welcome to the immersive world of C Arithmetic!\n");
    printf("Today, we will be exploring the calculation of Fibonacci sequence using a recursive approach.\n");
    printf("Let's begin!\n\n");
    
    int n;
    printf("Please enter the number of terms you would like to display in the Fibonacci sequence: ");
    scanf("%d", &n);
    
    printf("\nCalculating...\n\n");
    
    int fib[n];
    for(int i=0; i<n; i++) {
        fib[i] = fibonacci(i);
    }
    
    printf("The first %d terms of the Fibonacci sequence are:\n", n);
    for(int i=0; i<n; i++) {
        if(i == n-1){
            printf("%d", fib[i]);
        } else {
            printf("%d, ", fib[i]);
        }
    }
    
    printf("\n\nThank you for exploring the world of C Arithmetic with me!\n");

    return 0;
}

int fibonacci(int n) {
    if(n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    } 
}