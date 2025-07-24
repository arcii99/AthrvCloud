//FormAI DATASET v1.0 Category: Recursive ; Style: single-threaded
#include<stdio.h>

// Recursive function to calculate factorial
int factorial(int n) {
    // base case
    if (n == 0) {
        return 1;
    }
    // recursive case
    else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    // IllegalArgumentException handling
    if (num < 0) {
        printf("Factorial of negative numbers cannot be calculated.\n");
    }

    // calculate factorial using recursive function
    else {
        int result = factorial(num);
        printf("Factorial of %d is %d.\n", num, result);
    }

    return 0;
}