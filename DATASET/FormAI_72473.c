//FormAI DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>

int factorial(int n) {
    if(n < 0) {
        return -1; // invalid input case
    } else if(n == 0) {
        return 1; // base case
    } else {
        return n * factorial(n - 1); // recursive case
    }
}

int fibonacci(int n) {
    if(n < 0) {
        return -1; // invalid input case
    } else if(n == 0 || n == 1) {
        return n; // base case
    } else {
        return fibonacci(n-1) + fibonacci(n-2); // recursive case
    }
}

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    } else {
        return gcd(b % a, a); // recursive case
    }
}

int main() {
    int num; 
    printf("Enter a number: ");
    scanf("%d", &num);
    
    int fact = factorial(num);
    printf("%d! = %d\n", num, fact);
    
    int fib = fibonacci(num);
    printf("Fibonacci Sequence number at index %d is: %d\n", num, fib);
    
    int a, b;
    printf("Enter two numbers for gcd calculation: ");
    scanf("%d %d", &a, &b);
    int hcf = gcd(a, b);
    printf("GCD of %d and %d is: %d\n", a, b, hcf);
    
    return 0;
}