//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return (fibonacci(n-1) + fibonacci(n-2));
    }
}

int main() {
    printf("Get ready folks! We are about to generate some Fibonacci numbers using recursion.\n");

    int n;
    printf("Enter an integer number to get its Fibonacci number: ");
    scanf("%d", &n);

    int result = fibonacci(n);
    printf("The Fibonacci number for %d is: %d", n, result);

    printf("Jumping high with energy! Woooooooooo!\n");

    return 0;
}