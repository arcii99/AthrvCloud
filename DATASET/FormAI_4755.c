//FormAI DATASET v1.0 Category: Recursive ; Style: scalable
#include <stdio.h>

int fib(int n);

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The %dth number in the Fibonacci series is %d\n", num, fib(num));

    return 0;
}

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}