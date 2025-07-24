//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
/* Woohoo! Let's dive into the world of recursion! */

#include <stdio.h>

/* This function calculates the n-th Fibonacci number recursively */

int fibonacci(int n) {
    /* Base case */
    if (n == 0 || n == 1) {
        return n;
    }
    /* Recursive case */
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The %d-th Fibonacci number is %d \n", n, fibonacci(n));
    return 0;
}

/* Did you see that? We just unleashed the power of recursion to calculate the nth Fibonacci number! */