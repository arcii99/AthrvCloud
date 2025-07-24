//FormAI DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>

/*
 * Recursive function to calculate the factorial
 */
int fact(int n){

    if (n == 0 || n == 1) { // base case when n is 0 or 1
        return 1;
    } else {
        return n * fact(n-1); // recursive call
    }
}

/*
 * Recursive function to calculate the nth fibonacci number
 */
int fib(int n) {

    if (n == 0) { // base case when n is 0
        return 0; 
    } else if (n == 1) { // base case when n is 1
        return 1;
    } else {
        return fib(n-1) + fib(n-2); // recursive call
    }
}

/*
 * Main function to run the program
 */
int main() {

    // Calculate the factorial of 5 and print it
    int n = 5;
    int f = fact(n);
    printf("Factorial of %d is: %d\n", n, f);

    // Calculate the first 10 fibonacci numbers and print them
    printf("The first 10 fibonacci numbers are: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", fib(i));
    }

    return 0;
}