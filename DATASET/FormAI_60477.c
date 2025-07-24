//FormAI DATASET v1.0 Category: Physics simulation ; Style: recursive
#include <stdio.h>

// function that calculates the factorial using recursion
int factorial(int n) {
    if (n == 1) {
        // base case: 1! = 1
        return 1;
    } else {
        // recursive case: n! = n * (n-1)!
        return n * factorial(n-1);
    }
}

int main() {
    int n;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n); // read input from user
    
    printf("%d! = %d\n", n, factorial(n)); // use the factorial function to calculate the result
    
    return 0;
}