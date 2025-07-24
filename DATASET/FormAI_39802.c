//FormAI DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>

/*
This program calculates the factorial of a given number
using recursion
*/

int factorial(int n) {
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int main() {
    int n;
    printf("Enter a non-negative integer to calculate its factorial: ");
    scanf("%d", &n);
    
    if(n < 0)
        printf("Factorial of a negative number is undefined.");
    else {
        int result = factorial(n);
        printf("Factorial of %d is %d.", n, result);
    }
    
    return 0;
}