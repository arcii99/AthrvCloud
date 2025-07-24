//FormAI DATASET v1.0 Category: Math exercise ; Style: recursive
#include <stdio.h>

int factorial(int n) {
    if (n == 0) { // base case
        return 1;
    } else {
        return n * factorial(n-1); // recursive case
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Error: Factorial of a negative number does not exist.\n");
    } else {
        int result = factorial(n);
        printf("%d! = %d\n", n, result);
    }
    
    return 0;
}