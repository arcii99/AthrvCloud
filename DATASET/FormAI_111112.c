//FormAI DATASET v1.0 Category: Recursive ; Style: scientific
#include <stdio.h>

/* This program calculates the factorial of a given integer using recursion. 
   It takes the value of integer as input and returns the factorial value of that integer. */

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Factorial of negative numbers doesn't exist.");
    } else {
        printf("Factorial of %d is %d", num, factorial(num));
    }
    return 0;
}