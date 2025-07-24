//FormAI DATASET v1.0 Category: Educational ; Style: rigorous
#include <stdio.h>

// function to calculate factorial of a number 
int factorial(int n) {
    if (n < 0) {
        return -1; // error handling if the number is negative
    }
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// function to calculate fibonacci series up to n terms
void fibonacci(int n) {
    int term1 = 0, term2 = 1;
    printf("%d %d ", term1, term2);
    for (int i = 2; i < n; i++) {
        int nextTerm = term1 + term2;
        printf("%d ", nextTerm);
        term1 = term2;
        term2 = nextTerm;
    }
}

// program to demonstrate the usage of functions
int main() {
    int choice, n;
    printf("Choose an option:\n1. Calculate Factorial\n2. Generate Fibonacci Series\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n);
            printf("Factorial of %d is %d", n, factorial(n));
            break;
        case 2:
            printf("Enter the number of terms: ");
            scanf("%d", &n);
            printf("Fibonacci Series up to %d terms: ", n);
            fibonacci(n);
            break;
        default:
            printf("Invalid option");
    }
    return 0;
}