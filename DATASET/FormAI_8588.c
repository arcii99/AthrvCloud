//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci Sequence for %d terms:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}

void randomDelay() {
    int randomTime = rand() % 1001;
    clock_t delay = randomTime + clock();
    while (delay > clock());
}

int main() {
    int n;
    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &n);
    fibonacci(n);
    printf("\n");

    printf("Here is a visual representation of Fibonacci sequence:\n");
    for (int i = 1; i <= n; i++) {
        int fib = 0, t1 = 0, t2 = 1;
        for (int j = 1; j <= i; j++) {
            printf("%d ", fib);
            fib = t1 + t2;
            t1 = t2;
            t2 = fib;
            randomDelay();
        }
        printf("\n");
    }
    return 0;
}