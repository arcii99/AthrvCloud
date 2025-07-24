//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void async_factorial(int n, int* result);
void async_fibonacci(int n, int* result);

int main() {
    int n = 10;
    int result;

    async_factorial(n, &result);
    printf("Factorial of %d is: %d\n", n, result);

    async_fibonacci(n, &result);
    printf("Fibonacci of %d is: %d\n", n, result);

    return 0;
}

void async_factorial(int n, int* result) {
    if(n < 0) {
        *result = 0;
        return;
    } else if(n == 0) {
        *result = 1;
        return;
    }

    // asynchronously calculate factorial
    int m = n;
    *result = 1;
    while(m > 0) {
        srand(time(NULL));
        int rand_num = rand() % 10;
        if(rand_num % 2 == 0) {
            *result *= m;
        }
        m--;
    }
}

void async_fibonacci(int n, int* result) {
    if(n < 1) {
        *result = 0;
        return;
    } else if(n == 1 || n == 2) {
        *result = 1;
        return;
    }

    // asynchronously calculate fibonacci
    int a = 0;
    int b = 1;
    int c;
    for(int i = 2; i <= n; i++) {
        srand(time(NULL));
        int rand_num = rand() % 10;
        if(rand_num % 2 == 0) {
            c = a + b;
            a = b;
            b = c;
        }
    }
    *result = b;
}