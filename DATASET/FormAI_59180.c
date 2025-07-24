//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int choice, n, result;
    
    printf("Please enter a number:\n");
    scanf("%d", &n);
    
    printf("Please choose an option:\n");
    printf("1. Fibonacci sequence\n");
    printf("2. Factorial\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            result = fibonacci(n);
            printf("The %dth number in the Fibonacci sequence is %d\n", n, result);
            break;
        case 2:
            result = factorial(n);
            printf("%d! = %d\n", n, result);
            break;
        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}