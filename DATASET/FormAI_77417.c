//FormAI DATASET v1.0 Category: Recursive ; Style: expert-level
#include<stdio.h>

// Recursive function to calculate factorial
int fact(int n) {
    if (n <= 1)
        return 1;
    else
        return n * fact(n-1);
}

// Recursive function to calculate Fibonacci
int fib(int n) {
    if(n <= 1)
        return n;
    else
        return fib(n-1) + fib(n-2);
}

int main() {
    int n, choice;

    // menu to choose the function to evaluate
    printf("Enter your choice:\n");
    printf("1. Factorial\n");
    printf("2. Fibonacci\n");
    scanf("%d", &choice);

    printf("Enter the number:\n");
    scanf("%d", &n);

    switch(choice) {
        case 1:
            printf("Factorial of %d is: %d\n", n, fact(n));
            break;
        case 2:
            printf("Fibonacci value at %d is: %d\n", n, fib(n));
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}