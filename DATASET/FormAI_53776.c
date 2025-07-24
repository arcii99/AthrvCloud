//FormAI DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Recursive function to find the n-th Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Recursive function to count the number of digits in a number
int count_digits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1 + count_digits(n / 10);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("%d! = %d\n", num, factorial(num));
    printf("The %d-th Fibonacci number is %d\n", num, fibonacci(num));
    printf("The number of digits in %d is %d\n", num, count_digits(num));
    return 0;
}