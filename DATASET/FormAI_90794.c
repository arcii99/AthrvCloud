//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: random
#include <stdio.h>

int main() {

    int fib[50];

    fib[0] = 0;
    fib[1] = 1;

    int n = 2;

    while (n < 50) {
        fib[n] = fib[n-1] + fib[n-2];
        n++;
    }

    for (int i = 0; i < 50; i++) {

        if (fib[i] % 3 == 0 && fib[i] % 5 == 0) {
            printf("%d [FIZZBUZZ]\n", fib[i]);
        } else if (fib[i] % 3 == 0) {
            printf("%d [FIZZ]\n", fib[i]);
        } else if (fib[i] % 5 == 0) {
            printf("%d [BUZZ]\n", fib[i]);
        } else {
            printf("%d\n", fib[i]);
        }

    }

    return 0;
}