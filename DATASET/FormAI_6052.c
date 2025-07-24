//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: recursive
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}


int main() {
    int n = 10;
    int result = fibonacci(n);
    printf("The %dth term in the fibonacci series is %d\n", n, result);
    return 0;
}