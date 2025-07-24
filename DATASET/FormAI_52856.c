//FormAI DATASET v1.0 Category: Recursive ; Style: future-proof
#include <stdio.h>

int fib(int num) {
    if (num <= 1) {
        return num;
    } else {
        return fib(num - 1) + fib(num - 2);
    }
}

int main() {
    int num = 10;
    int result = fib(num);
    
    printf("Fibonacci of %d: %d", num, result);

    return 0;
}