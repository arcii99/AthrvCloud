//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int recursive_fibonacci(int n) {
    if(n < 2) {
        return n;
    }
    else {
        return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
    }
}

int iterative_fibonacci(int n) {
    int prev = 0;
    int current = 1;
    int temp;
    int i;

    for(i=0; i<n; i++) {
        temp = current + prev;
        prev = current;
        current = temp;
    }

    return prev;
}

int main() {
    int number = 40;
    clock_t start_time;
    double recursive_time, iterative_time;

    start_time = clock();
    recursive_fibonacci(number);
    recursive_time = (double)(clock()-start_time)/CLOCKS_PER_SEC;

    start_time = clock();
    iterative_fibonacci(number);
    iterative_time = (double)(clock()-start_time)/CLOCKS_PER_SEC;

    printf("Computing the %dth Fibonacci number:\n", number);
    printf("Recursive function took %f seconds.\n", recursive_time);
    printf("Iterative function took %f seconds.\n", iterative_time);

    return 0;
}