//FormAI DATASET v1.0 Category: Recursive ; Style: content
/* This program demonstrates the use of recursion in the calculation of Fibonacci numbers. 
   The user is prompted to enter the number of terms to be generated, and the program calculates
   and displays the corresponding Fibonacci sequence using a recursive function. */
   
#include <stdio.h>

// Recursive function to calculate Fibonacci numbers
int fib(int n) {
    if (n == 0 || n == 1) { // Base cases
        return n;
    } else { // Recursive case
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int n, i;
    
    printf("Enter the number of terms to be generated: ");
    scanf("%d", &n);
    
    printf("The first %d terms of the Fibonacci sequence are:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    
    return 0;
}