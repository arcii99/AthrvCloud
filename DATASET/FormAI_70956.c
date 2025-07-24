//FormAI DATASET v1.0 Category: Recursive ; Style: intelligent
#include <stdio.h>

/* This is a recursive function that calculates the factorial of a number */
int factorial(int num) {
    if(num == 0) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

/* This is a recursive function that calculates the nth term of the Fibonacci sequence */
int fibonacci(int num) {
    if(num == 1 || num == 2) {
        return 1;
    } else {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

/* This is a function that calls the recursive functions and prints the output */
void recursiveFunction() {
    int fact = factorial(5);
    int fib = fibonacci(7);
    printf("Factorial of 5 = %d\n", fact);
    printf("7th term of Fibonacci series = %d\n", fib);
}

int main() {
    printf("This program demonstrates the use of recursive functions in C.\n\n");
    recursiveFunction();
    return 0;
}