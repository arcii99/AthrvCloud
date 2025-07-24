//FormAI DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
#include <stdio.h>

int fibonacci(int n) {
    if (n < 2) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n = 10; // Change this to any number to get the nth fibonacci number
    int fib_n = fibonacci(n);
    printf("The %dth fibonacci number is %d", n, fib_n);
    return 0;
}